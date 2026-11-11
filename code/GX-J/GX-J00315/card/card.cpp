#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
ll n,m,a[N],cnt[N],num[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		vector<ll> v;
		bool vis[N];
		memset(vis,0,sizeof(vis));
		for(int j = i;j<=n;j++) v.push_back(a[j]);
		for(int j = 0;j<int(v.size());j++){
			if(!vis[v[j]]){
				vis[v[j]] = 1;
			}
			else{
				for(int k = j-1;k>=0;k--){
					if(v[k] == v[j]) break;
					vis[v[k]] = 0;
				}
			}
		}
		for(int j = 1;j<=m;j++)
			if(vis[j]) cnt[j]++;
	}
	for(int i = 1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
