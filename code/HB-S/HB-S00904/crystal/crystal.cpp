#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
typedef long long ll;
int n;
ll m,a[N];
__int128 d[N],sum[N];
bool check(int i,int mid){
	return sum[mid]-sum[i]-(i-mid)*d[i]<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i-1]=a[i]-a[i-1];
	}
	for(int i=n-1;i>=1;i--)
		d[i]+=d[i+1];
	for(int i=n-1;i>=1;i--)
		sum[i]=sum[i+1]+d[i];
	ll most=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,ans=i;
		while(l<=r){
			int mid=l+(r-l)/2;
			if(check(i,mid)){
				ans=mid;
				r=mid-1;
			} else {
				l=mid+1;
			}
		}
		most=max(most,1ll*i-ans+1);
	}
	cout<<most<<'\n';
	return 0;
}