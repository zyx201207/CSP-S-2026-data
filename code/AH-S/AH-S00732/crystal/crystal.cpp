#include <iostream>
#include <utility> 
#include <algorithm>
#include <cassert>
using namespace std;
const int N=5e5+5;
int n;
int ans=1;
long long m,sm[N],a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sm[i]=sm[i-1]+a[i];
	int lst=1;
	for(int i=2;i<=n;i++){
		while(lst<=i&&(-sm[i]+sm[lst-1]+1ll*(i-lst+1)*a[i])>m) ++lst;
		ans=max(ans,i-lst+1);
	}
	cout<<ans;
	return 0;
}
