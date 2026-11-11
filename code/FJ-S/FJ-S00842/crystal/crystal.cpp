#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans=1,l;
int a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	l=1;
	for(int i=2;i<=n;i++){
		while(l<=n&&(i-l)*a[i]-(s[i-1]-s[l-1])>m)
			l++;
		ans=max(ans,i-l+1);	
	}
	cout<<ans<<'\n';
	return 0;
} 
