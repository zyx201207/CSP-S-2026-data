#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int n,m,k,c[N],mp[N];
int a[N],t[N],s[N],mx;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;a[0]=-1e18;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			m++;
			mp[m]=a[i];
		}
		t[m]++;
	}
	for(int i=1;i<=m;i++){
		c[i]=c[i-1]+t[i];
		s[i]=s[i-1]+c[i-1]*(mp[i]-mp[i-1]);
	}
	for(int i=1;i<=m;i++){	
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			int x=s[i]-s[mid-1]-c[mid-1]*(mp[i]-mp[mid-1]);
			if(x>k)l=mid+1;
			else r=mid-1;
		}
		int x=s[i]-s[r]-c[r]*(mp[i]-mp[r]);
		x=k-x;
		if(r>0)x=x/(mp[i]-mp[r]);
		else x=0;
		mx=max(mx,c[i]-c[r]+x);
	}
	cout<<mx;
	return 0;
} 
