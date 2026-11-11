#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=500005;
int n,m,a[MAXN];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cout<<i<<" ";
	return 0;
} 
