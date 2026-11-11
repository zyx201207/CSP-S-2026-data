#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],ans=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n,j=n-1;i>=1;i--){
		if(i!=n)m+=(i-j)*(a[i+1]-a[i]);
		while(m>=a[i]-a[j]&&j>=1){
			m-=a[i]-a[j--];
		}
		ans=max(ans,i-j);
	}
	cout<<ans;
	return 0;
}
