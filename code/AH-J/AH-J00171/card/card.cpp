#include<bits/stdc++.h>
using namespace std;
int a[500100];
int t[300100];
vector<int> g[300100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			t[a[j]]++;
			int l=g[a[j]].size();
			j=g[a[j]][l-1];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
