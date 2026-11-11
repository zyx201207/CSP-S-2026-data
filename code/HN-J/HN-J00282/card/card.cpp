#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],ton[500005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ton[a[i]]++;
	}
	for(int i=1;i<=m;i++) if(ton[i]>=1) cout<<i;
	return 0;
}

