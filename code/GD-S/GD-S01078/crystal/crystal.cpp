#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <map>
#define int long long
using namespace std;

const int maxn = 5e5+10;
int n,m,q,k,p;
int pre[maxn],a[maxn];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=1,r=0;
	int len=0,tot=0;
	int ans=-0x3f3f3f3f;
	for(r=1;r<=n;r++){
		while((r-l+1)*a[r]-(pre[r]-pre[l-1])>m) l++;
		ans=max(ans,r-l+1); 
	}
	cout<<ans<<endl;
	return 0;
}
