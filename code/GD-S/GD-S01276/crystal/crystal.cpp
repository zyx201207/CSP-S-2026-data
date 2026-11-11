#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+7;
int n,m,a[N],sum[N],f[N];
int max(int a,int b){
	return a>b?a:b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)a[i]=a[i+1]-a[i];
	a[n]=m+10;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1,r=1,flag=0,ans=1;
	while(l<=n&&r<=n){
		while(flag<=m&&r<=n)flag+=(r-l+1)*a[r++];
		r--;
		flag-=sum[r]-sum[l-1];
		ans=max(ans,r-l+1);
		r++;
		l++;
	}
	cout<<ans;
	return 0;
}//这是一场豪赌
