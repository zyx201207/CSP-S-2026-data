#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int as[35],bs[35],n,m,a[N],maxs;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxs=max(maxs,a[i]);
	}
	cout<<maxs;
	return 0;
}
