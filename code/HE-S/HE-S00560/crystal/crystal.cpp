#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+100;
ll a[N],n,m,d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){scanf("%lld",&a[i]);}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){d[i-1]=a[i]-a[i-1];}
	ll ans=0,l=1,r=0,sum=0;
	while(r<n){
		ans=max(ans,r-l+2);
		if(sum+(r-l+2)*d[r+1]>m){
			sum-=(a[r+1]-a[l]);
			l++;
		}
		else if(r<n)r++;sum+=d[r]*(r-l+1);
	}
	cout<<ans;
	return 0;
} 
