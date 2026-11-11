#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200005],sum[200005],ma;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	ma=a[1];
	for(int i=2;i<=k;i++){
		ma=ma&a[i];
	}
	cout<<ma;
	return 0;
}
