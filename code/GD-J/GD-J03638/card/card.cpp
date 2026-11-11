#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],s[500010],ans[300010];
vector<int>b[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++) s[b[i][b[i].size()-1]]=b[i].size();
	for(int i=2;i<=n;i++){
		if(s[i]) s[i]+=s[i-1];
		else s[b[a[i]][b[a[i]].size()-1]]+=s[i-1];
	}
	for(int i=1;i<=n;i++) ans[a[i]]+=s[i];
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
//11:52  100
