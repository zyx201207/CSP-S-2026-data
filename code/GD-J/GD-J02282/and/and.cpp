#include<bits/stdc++.h>
using namespace std;
int n,m;
long long s[200005];
int main(){
	freopen(and.in,"r",stdin);
	freopen(and.out,"w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	sort(s+1,s+n+1,greater<int>());
	int z=s[1];
	for(int i=2;i<=m;i++) z&=s[i];
	cout<<z;
	return 0;
}
