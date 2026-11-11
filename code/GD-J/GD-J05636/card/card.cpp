#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int last[300005],ans[300005];
vector<int>v[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		if(last[a[i]]==0){
			last[a[i]]=i;
			v[i]=v[i+1];
			v[i].push_back(a[i]);
		}
		else {
			v[i]=v[last[a[i]]];
		}
		for(int j=0;j<v[i].size();j++)ans[v[i][j]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
