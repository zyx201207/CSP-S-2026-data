#include <bits/stdc++.h>
#define ll long long
#define up(i,a,b) for (int i=(a);i<=(b);i++)
#define down(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;
const int N=5e5+5;
int n;ll m;
ll a[N],sum[N];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	up(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	up(i,1,n) sum[i]=sum[i-1]+a[i];
	int pos=1;
	up(i,1,n){
		while (pos<=n&&(a[i]*(i-pos+1))-(sum[i]-sum[pos-1])>m) pos++;
		ans=max(ans,i-pos+1);
	}
	cout<<ans;
	return 0;
}
