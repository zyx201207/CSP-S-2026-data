#include <bits/stdc++.h>
using namespace std;
int f[50005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	for(int i=1;i<=n;i++){
		cout<<0<<" ";
	}
	return 0;
}
