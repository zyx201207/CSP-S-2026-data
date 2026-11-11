#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long a[N],ans,n;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
		cin >> c[i];
	}
	long long l=1,r=n;
	while(l<r){
		long long mn=min(a[l],a[r]);
		if(c[l]!=c[r]) ans += mn;
		a[l] -= mn;
		a[r] -= mn;
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout << ans << '\n';
	return 0;
}
