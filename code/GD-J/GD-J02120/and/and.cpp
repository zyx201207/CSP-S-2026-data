#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+9;
int a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	bool f=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]%2==0)f=0;
	}
	sort(a+1,a+n+1);
	if(f==1)cout<<a[n-m+1];
	return 0;
} 
