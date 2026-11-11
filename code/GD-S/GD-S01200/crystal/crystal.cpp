#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+10;
int n,m,a[N],ans=1,tot;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m;
	int L=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		int c=a[i]-a[i-1];
		tot+=(i-L)*c;
		while(L<=i&&tot>m){
			tot-=a[i]-a[L];
			L++;
		}
		ans=max(ans,i-L+1);
	}
	cout<<ans;
	return 0;
}
