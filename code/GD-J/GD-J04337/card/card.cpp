#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2,M=3e5+2;
int n,m,a[N],ans[M];
vector<int>vis[M];
unordered_map<int,int>mp;
int main(){
	freopen("card.in","r",stdin),freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i],vis[a[i]].emplace_back(i),mp[i]=a[i];
	ans[a[n]]=n;
	for(int i=n-1,id;i>=1;--i){
		for(int j=i+1;j<=n;++j){
			if(vis[a[j]].size()<2) continue;
			if(a[i]!=a[n]){
				int id=*upper_bound(vis[a[j]].begin(),vis[a[j]].end(),i);
				if(mp[id-1] && mp[id-1]!=i) ans[a[i]]+=i-vis[a[j]][mp[id-1]];
			}
		}
		if(!ans[a[i]]) ans[a[i]]=i;
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<' ';
	fclose(stdin),fclose(stdout);
	return 0;
}
