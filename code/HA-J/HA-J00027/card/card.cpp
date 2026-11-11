#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 500005

ll a[MAXN],n,m,idx,vis[MAXN];

map<ll,ll>ans;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.our","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		map<ll,ll>mp;
		memset(vis,0,sizeof vis);
		idx++;
		for(int j=idx;j<=n;j++){
			if(mp[a[j]]==0) mp[a[j]]=j;
			else{
				for(int k=mp[a[j]];k<j;k++){
					vis[k]=1;
				}
				mp[a[j]]=0;
			}
		}
		for(int j=idx;j<=n;j++){
			if(vis[j]==0){
				ans[a[j]]++;
			}
		}
	}
	for(int j=1;j<=m;j++){
		cout<<ans[j]<<" ";
	}
	return 0;
}
