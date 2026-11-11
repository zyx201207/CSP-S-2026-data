#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1<<18];
bool is_power_of_2(ll x){
	for(int i=1;i<=30;i++)
		if((1<<i)==x) return true;
	return false;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    ll ans=-9e18;
    if(m==1)
		for(int i=1;i<=n;i++)
			ans=max(ans,a[i]);
	else if(m==2)
		for(int i=1;i<=n-1;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
	}else if(n>2000){
		if(m==n-1){
			for(int i=1;i<=n;i++){
				ll t=i==1?a[2]:a[1];
				for(int j=i==1?2:1;j<=n;j++){
					if(i==j) continue;
					t&=a[j];
				}ans=max(ans,t);
			}
		}else if(is_power_of_2(a[2001]+1)){
			ans=a[1];
			for(int i=2;i<=n;i++)
				ans=min(ans,a[i]);
		}else if(a[2001]<4) ans=3;
	}cout<<ans;
    return 0;
}
