#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],f[500005],ans=-1;
bool cmp(ll x,ll y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	a[0]=0;
	a[n+1]=a[n];
	for (int i=1;i<=n;i++){
		f[i]=a[i]-a[i-1];
	}
	ll l=1,r=1,s=0,sum;
	while (l<=r && r<=n){
		sum=r-l+1;
		if ((f[r+1]*sum)<=(m-s)){
			s+=f[r+1]*sum;
			r++;
			sum++;
			ans=max(ans,sum);
		}
		else{
			s-=a[r]-a[l];
			l++;
			sum--;
			ans=max(ans,sum);
		}
	}
	cout<<ans;
	return 0;
}
