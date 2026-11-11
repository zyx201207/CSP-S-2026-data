#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],c[500005];
int s1[500005],s2[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		s1[i]=s1[i-1]+c[i];
		s2[i]=s2[i-1]+s1[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(s1[i]*(i-mid)-(s2[i-1]-s2[mid])<=m)r=mid;
			else	l=mid+1;
		}
		ans=max(i-l+1,ans);
	}
	cout<<ans;
	return 0;
}

