#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+5;

int n,m,a[N],s[N];

signed main(){
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int ans=0;
	for(int i=1,j=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
		while(j<i&&a[i]*(i-j+1)-s[i]+s[j-1]>m)++j;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
}
