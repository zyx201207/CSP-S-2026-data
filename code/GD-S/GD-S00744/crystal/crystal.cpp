#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1;
	for(int i=2,j=1,x=0;i<=n;i++){
		x+=(a[i]-a[i-1])*(i-j);
		while(x>m)x-=a[i]-a[j],j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans<<'\n';
}
