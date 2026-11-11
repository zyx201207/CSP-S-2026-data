#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans++;
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
}
