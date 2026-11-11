#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m,a[500010],d[500010];
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	d[1]=0;
	for(ll i=2;i<=n;i++) d[i]=a[i]-a[i-1];
	ll sum=0,tot=0,ans=0;
	for(ll i=1,j=1;i<=n && j<=n;j++){
		sum+=d[j]*(j-i);
		tot+=d[j];
		while(sum>m){
			tot-=d[i];
			sum-=tot;
			i++;
		}
		ans=max(ans,(ll)(j-i)+1);
	}
	cout<<ans<<'\n';
	return 0;
}
