#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		ll o=m,sum=0;
		for(ll j=i-1,k=i+1;o>0;){
			if(a[i]-a[j]<o&&j>0) sum++,o-=a[i]-a[j],j--;
			if(a[k]-a[i]<o&&k<n) sum++,o-=a[k]-a[i],k++;
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}
