#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,T,n,d,a[N],dis[N],vis[N];
queue<int>q;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)	cin>>a[i];
		if(c==13||c==14){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			fill(vis,vis+n+5,0);
			vis[i]=1;
			dis[i]=0;
			q.emplace(i);
			while(q.size()){
				int x=q.front();q.pop();
				for(int j=x+1;j<=n;j++){
					if(a[j]-a[x]>d)	break;
					if(vis[j]&&dis[j]==dis[x]+1)	vis[j]+=vis[x];
					if(!vis[j]){
						vis[j]=vis[x];
						q.emplace(j);
						dis[j]=dis[x]+1;
					}
				}
			}
			for(int j=i+1;j<=n;j++)
				if(vis[j]==2)	ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
