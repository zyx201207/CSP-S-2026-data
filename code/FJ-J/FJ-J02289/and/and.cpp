#include <bits/stdc++.h>
using namespace std;
int f[10005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	sort(f+1,f+n+1);
	cout<<f[m];
	return 0;
}
