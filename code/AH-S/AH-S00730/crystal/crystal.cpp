#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],sum[N];
ll n,m,ans=0;
bool isok(int x){
	for(int i=0;i<=n-x;i++){
		ll t=a[i+x]*x-(sum[i+x]-sum[i]);
		if(m>=t)return 1;
		//cout<<t<<' ';
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1,r=n,mid;
	while(l<=r){
		mid=l+(r-l)/2;
		if(isok(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
		//cout<<l<<' '<<r<<' '<<mid<<endl;
	}
	cout<<ans;
	return 0;
} 
