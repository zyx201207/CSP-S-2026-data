#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],b[500005],sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 2;i<=n;i++){
		b[i-1]=a[i]-a[i-1];
	}for(int i = 1;i<n;i++){
		sum[i]=sum[i-1]+b[i];
	}int Sum=0,I=1;
	for(I;Sum<=m;I++){
		Sum+=b[I]*I;
	}I-=1;
	Sum-=b[I]*I;
	int l=1,r=l+I-2,sz=I-1,ans=sz;
	while(l<=n){
		l++;
		sz--;
		Sum-=sum[r]-sum[l-1];
		while(Sum<=m&&r<=n){
			Sum+=b[r+1]*(sz+1);
			r++;
			sz++;
		}r--;
		sz--;
		Sum-=b[r+1]*(sz+1);
		ans=max(ans,sz);
	}cout<<ans+1;
	return 0;
}