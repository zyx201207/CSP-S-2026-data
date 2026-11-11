#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int c,n,m,q,t;
int ans;
int a[MAXN],sum[MAXN];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		while(m<a[i]*(i-l+1)-(sum[i]-sum[l-1])){
			l++;
		}
		if(m>=a[i]*(i-l+1)-(sum[i]-sum[l-1])){
			ans=max(ans,i-l+1); 
		}
//		cout<<l<<" ";
	}
	cout<<ans;
	return 0;
}
