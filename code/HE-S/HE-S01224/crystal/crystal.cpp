#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
		if(a[i-1]+m>=(a[i]-a[i-1])*(i-1)){
			ans=i;
		} else break;
	}
	cout << ans;
	return 0;
}
