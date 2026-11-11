#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[501005],b[500009],sum[500007];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		sum[i]+=b[i]+sum[i-1];
	}
	int l=1,r=1,cnt=0,maxx=-10000,minn,midd=(l+r)/2;
	while(l<=r&&r<=n){
		if(cnt<=m) maxx=max(maxx,r-l+1);
		if(cnt>m){
			cnt-=a[r]-a[l];
			l++;
		}else{
			cnt+=(r-l+1)*b[r];
			r++;
		}
	}
	cout<<maxx;
	return 0;
} 
