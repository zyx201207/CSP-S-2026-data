#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],m,ans[N];
bool vis[N],mp[N];
vector<int>ve[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) ve[a[i]].push_back(i);
	for(int i=1;i<=m;i++) reverse(ve[i].begin(),ve[i].end());
//	for(int i=1;i<=n;i++){
//		for(auto it:ve[a[i]]) cout<<it<<' ';
//		cout<<'\n';
//	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) vis[i]=0;
		for(int j=i;j<=m;j++) mp[i]=0;
		for(int j=i;j<=n;j++){
			if(ve[a[i]].size()<2) continue;
//			cout<<a[i]<<' '<<ve[a[i]][ve[a[i]].size()-1]+1<<'\n';
			for(int k=ve[a[i]][ve[a[i]].size()-1]+1;k<ve[a[i]][0];k++) vis[k]=1;
		}
		for(int j=i;j<=n;j++){
			if(!vis[j]&&!mp[a[j]]){
				ans[a[j]]++;
				mp[a[j]]=1;
			}
		}
		ve[a[i]].pop_back();
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
