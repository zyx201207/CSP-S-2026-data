#include<bits/stdc++.h>
#define l long long
using namespace std;
struct dr{
	l z,b;
}; 
l c,t,n,d,a[2000020],s,cnt,ans;
void bfs(int x,int y){
	queue<dr> q;
	q.push({x,0});
	while(!q.empty()){
		dr u=q.front();
		q.pop();
		if(u.b>s)continue;
		if(u.z==y){
			if(u.b==s)cnt++;
			else{
				s=u.b;
				cnt=1;
			}
		}
		for(int i=u.z+1;i<=y;i++){
			if((a[i]-a[u.z])>d)break;
			q.push({i,u.b+1});
		}
	}
	if(cnt==2)ans++;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for(int i=0;i<t;i++){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				s=n+1;
				cnt=0;
				bfs(i,j);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
