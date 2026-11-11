#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mid (l+r>>1)
#define endl '\n'

const int mx=5e5+5;
const ll inf=1e18;
int n,s;
ll m,a[mx],pr[mx];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	a[n+1]=-inf;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pr[i]=pr[i-1]+a[i];
	for(int j=1,i=1;i<=n;i++){
		if(a[i+1]==a[i]) continue;
		while(a[i]*(i-j+1)-(pr[i]-pr[j-1])>m) j++;
		s=max(s,i-j+1);
	}
	cout<<s;
	return 0;
}
