#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e5+10;
ll n,m,a[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//ll ans=a[n];
	//for(int i=n-1;i>n-m;i--){
	//	ans=ans&a[i];
	//}cout<<ans;
	cout<<a[n-m];
	return 0;
}
