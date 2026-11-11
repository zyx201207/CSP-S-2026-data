#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
ll n,m;
const ll MAXN=5e5+5;
ll a[MAXN],ans[300005],ls[300005],ans2[300005],vis[300005],minn[300005];
vector<ll> pos[300005];
bool tepan1=true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		pos[a[i]].push_back(i);
		ls[a[i]]=max((ll)i,ls[a[i]]);
	}
	for(int i=1;i<n;++i){
		if(a[i]>a[i+1]){
			tepan1=false;
		}
	}
	for(int i=1;i<=m;++i){
		ans[i]=ls[i];
		//cout<<ans[i]<<'\n';
	}
	if(n<=5000){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				vis[j]=0;
				minn[j]=1e18;
			}
			for(int j=i;j<=n;++j){
				if(vis[a[j]]){
					vis[a[j]]=1;
					//cout<<minn[a[j]]<<" "<<j<<'\n';
					for(int k=minn[a[j]]+1;k<j;++k){
						if(vis[a[k]]){
							vis[a[k]]=0;
							if(minn[a[k]]>=minn[a[j]]){
								minn[a[k]]=1e18;
							}
						}
					}
					minn[a[j]]=j;
				}
				else if(!vis[a[j]]){
					minn[a[j]]=min(minn[a[j]],(ll)j);
					vis[a[j]]=1;
				}
			}
			for(int j=1;j<=m;++j){
				if(vis[j]){
					if(j==3){
						//cout<<i<<'\n';
					}
					ans2[j]++;
				}
			}
		}
		for(int i=1;i<=m;++i){
			cout<<ans2[i]<<" ";
		}
	}
	else if(tepan1){
		for(int i=1;i<=m;++i){
			cout<<ans[i]<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
