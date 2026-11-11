#include<bits/stdc++.h>
using namespace std;
long long dis[2000010],c,t,n,d,a[2000010],cnt,pos,now,minn,ans;
long long vis[2000010];
struct island{
	int id,step;
}ild;
queue<island>q;
bool bfs(int bg,int ed){
	cnt=0;
	ild.id=bg;
	ild.step=0;
	q.push(ild);
	while(!q.empty()){
		pos=q.front().id;
		now=q.front().step;
		if(pos==ed){
			if(minn>now){
				minn=now;
				cnt=1;
			}
			else if(minn==now){
				cnt++;
			}
		}
		q.pop();
		for(int i=pos+1;i<=ed;i++){
			if(a[i]-a[pos]>d){
				break;
			}
			if(dis[i]>=now+1){
				dis[i]=now+1;
			}
			ild.id=i;
			ild.step=now+1;
			q.push(ild);
		}
	}
	if(cnt==2){
		return true;
	}
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				minn=0x3f3f3f3f;
				for(int k=i;k<=j;k++){
					dis[k]=0x3f3f3f3f;
					vis[k]=0;
				}
				if(bfs(i,j)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
