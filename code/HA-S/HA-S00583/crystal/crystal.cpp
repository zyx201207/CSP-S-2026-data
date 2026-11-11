#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
long long n,m,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++){ 
		cin >>a[i];
	}
	sort(a+1,a+1+n);
	ll ans=a[1]+a[2];
	cout <<abs(ans);
	return 0;
} 
