#include<bits/stdc++.h>
using namespace std;
int a[200010];
int b[500010];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		set<int>s;
		for(int j=i; j<=m; j++) {
			s.insert(a[j]);
		}
		for(int j=1; j<=s.size(); j++) {
			b[i]++;
		}
	}
	for(int i=1; i<=n; i++) {
		if(b[i]==0)
			cout<<b[i]<<" ";
	}
	return 0;
}
