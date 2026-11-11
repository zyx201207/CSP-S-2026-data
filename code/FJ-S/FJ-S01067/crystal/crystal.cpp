#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,m;
ll a[N],sum[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	cout<<(ll)(0x3f3f3f3f3f3f3f3f);
	cin>>n>>m;
//	memset(f,0x3f,sizeof(f));
//	f[0][0]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
//	for(int i=1;i<=n;i++){
//		f[i][0]=0;
//		for(int j=1;j<=i;j++){
//			cout<<"----"<<i<<" "<<j<<endl;
//			f[i][j]=f[i-1][j];
//			for(int k=i-j;k<i-1;k++){
//				ll x=a[i]*(i-k)-(sum[i]-sum[k]);
//				cout<<k<<" "<<j-(i-k)<<"->"<<f[k][j-(i-k)]<<" "<<x<<endl;
//				f[i][j]=min(f[i][j],f[k][j-(i-k)]+x);
//			}
//			if(f[i][j]>m)f[i][j]=0x3f3f3f3f3f3f3f3f;
//			cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
//		}
//	}
//	for(int i=n;i>=0;i--){
//		if(f[n][i]<m){
//			cout<<i;
//			return 0;
//		}
//	}
	int l=1,ans=1;
	ll s=0;
	for(int r=2;r<=n;r++){
		s=s+(a[r]-a[r-1])*(r-l);
		while(s>m&&l<r){
			s-=(a[r]-a[l++]);
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
}
//fc crystal.out Crystal.out
