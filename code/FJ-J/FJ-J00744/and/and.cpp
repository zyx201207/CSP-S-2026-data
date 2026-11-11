#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[200005];
long long p[40];
int vis[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<long long>g[40];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	p[0]=1;
	for(int i=1;i<=35;i++){
		p[i]=p[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		for(int j=35;j>=0;j--){
			if(a[i]-p[j]>=0){
				g[j].push_back(i);
				//cout<<j<<" ";
				a[i]-=p[j];
			}
		}
		//cout<<"\n";
	}
//	for(int i=4;i>=0;i--){
//		for(int j=0;j<g[i].size();j++){
//			cout<<g[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	bool k=0;
	for(int i=35;i>=0;i--){
		
		if(k==1&&g[i].size()>=m){
			//cout<<i<<"\n";
			int u=0;
			for(int j=0;j<g[i].size();j++){
				if(vis[g[i][j]]==1){
					//cout<<vis[g[i][j]]<<" ";
					u++;
					//cout<<u<<" ";
				}
			}
			//cout<<"\n";
			if(u>=m){
				ans+=p[i];
				for(int j=0;j<g[i].size();j++){
					if(vis[g[i][j]]==1){
						vis[g[i][j]]=2;
						//cout<<g[i][j]<<" ";
					}
				}
				//cout<<vis[1]<<"\n";
				for(int j=1;j<=n;j++){
					if(vis[j]==1){
						vis[j]=0;
					}
					if(vis[j]==2){
						vis[j]=1;
						//cout<<j<<" gwegg";
					}
				}
				//cout<<"\n";
			}
			
		}
		if(k==0&&g[i].size()>=m){
			for(int j=0;j<g[i].size();j++){
				vis[g[i][j]]=1;
			}
			k=1;
			ans+=p[i];
			//cout<<i<<"\n";
		}
	}
	cout<<ans;
	return 0;
}
