#include <bits/stdc++.h>
using namespace std;
#define I cin>>
#define O cout<<
typedef long long ll;
const int N=5e5+5;
int n,ans;
ll m,a[N],b[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	I n >> m;
	for(int i=1;i<=n;i++) I a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	int l=0;
	for(int r=1;r<=n;r++){
		while((r-l)*a[r]-(b[r]-b[l])>m) l++;
		ans=max(ans,r-l);
	}
	O ans;
	return 0;
}
