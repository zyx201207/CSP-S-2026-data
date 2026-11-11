#include<bits/stdc++.h>
#define int long long
using namespace std;
const int hxy=2e6+7;
int a[hxy],b[hxy],n,m,j,k,l,c[hxy],d,x,y,ans,sum,vis[2000][2000],gy,t,cnt[2000][2000];
struct pp{
	int x,t;
};
main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>gy>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		int uu=1e18;
		memset(b,0,sizeof(b));
		memset(vis,0,sizeof(vis));
	    memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			a[i]+=700;
			uu=min(uu,a[i]);
			b[a[i]]=1;
		}
		for(int i=1;i<=n;i++){
			queue<pp>q;
			q.push({a[i],0});
			memset(c,0,sizeof(c));
			c[a[i]]=1;
			while(q.size()>0){
				int x=q.front().x;
				int t=q.front().t;
				q.pop();
				if(t>1) if(vis[a[i]][x]==0)vis[a[i]][x]=t;
				for(int k=x-d;k<=x+d;k++){
					if(b[k]==1&&c[k]==0){
						q.push({k,t+1});
						c[k]=1;
					}
				}
			}
		}
		for(int i=uu;i<=n+uu-1;i++){
			for(int j=uu;j<=n+uu-1;j++){
				if(vis[i][j]!=0){
					queue<pp>q;
					q.push({i,0});
					while(q.size()>0){
						int x=q.front().x;
						int t=q.front().t;
						q.pop();
						if(t==vis[i][j]){
							if(x==j) cnt[i][j]++; 
						}
						else{
							for(int k=x-d;k<=x+d;k++){
								if(b[k]==1){
									q.push({k,t+1});
								}
							}
						}
					}
				}
			}
		}
		for(int i=uu;i<=n+uu-1;i++){
			for(int j=uu;j<=n+uu-1;j++){
				if(cnt[i][j]==2)ans++;
			}
		}
		cout<<ans/2;
	}
}
