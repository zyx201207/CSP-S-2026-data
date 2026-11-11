#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,ans;
int a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	ans=1;
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
		if(i==1)
			continue;
		int l=1,r=i,mid=0;
		while(l<r){
			mid=(l+r)>>1;
			if(s[i]-s[mid-1]+m>=(i-mid+1)*a[i])
				r=mid;
			else
				l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
