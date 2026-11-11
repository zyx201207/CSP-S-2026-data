#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll l=1,r=1,tot=0;
	while(r<=n){
		if(tot<=m){
			r++;
			ans=max(ans,r-l+1);
			tot+=(r-l)*(a[r]-a[r-1]);
		}else{
			l++;
			tot-=(a[r]-a[l-1]);
		}
	}
	cout<<ans-1;
	return 0;
} 



