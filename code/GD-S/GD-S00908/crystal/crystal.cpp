#include <bits/stdc++.h>
using namespace std;
const int N=5e5+8;
long long a[N],m,tmp=0;
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >>n>>m;
	for (int i=1;i<=n;++i){
		cin >>a[i];
	}
	sort(a+1,a+1+n);
	int ans=1;
	for (int i=2,j=1;i<=n;++i){
		tmp+=1ll*(a[i]-a[i-1])*(i-j);
		while (tmp>m) tmp-=(a[i]-a[j]),++j;
		ans=max(ans,i-j+1);
	}
	cout <<ans;
	return 0;
}
