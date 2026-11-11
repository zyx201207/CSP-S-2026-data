#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
long long a[2000006],v[2000005],v1[2000006],ans,b[2000005];
struct node{
	long long x,step;
};
queue <node> q;
void bfs(int s){
	q.push({s,0});
	v[s]=1;
	while(!q.empty()){
		node u=q.front();
		q.pop();
		for(int i=u.x+1;i<=n;i++){
			if(a[i]-a[u.x]<=d){
				if(v[i]==0){
					q.push({i,u.step+1});
				}
				if(u.step+1==b[i])v[i]++;
			}
			else break;
		}
	}
}
void bfs1(){
	q.push({a[1],0});
	v1[1]=1;
	while(!q.empty()){
		node u=q.front();
		q.pop();
		for(int i=u.x+1;i<=n;i++){
			if(a[i]-a[u.x]<=d){
				if(b[i]==0) b[i]=u.step+1;
				v1[i]=1;
				q.push({i,u.step+1});
			}
			else break;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		memset(v1,0,sizeof(v1));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		bfs1();
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i;j<=n;j++){
				if(v[j]==2) ans++;
			}
			memset(v,0,sizeof(v));
		}
		cout<<ans;
	}
	
	return 0;
}
