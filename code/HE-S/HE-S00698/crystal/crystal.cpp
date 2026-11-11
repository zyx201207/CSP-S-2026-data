#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+50,M=5e3+30;
ll n,m,ans,d,a[N];
__int128 sum; 
bool f=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	d=a[2]-a[1];
    for(int i=1;i<=n;i++){
    	if(i>1&&a[i+1]-a[i]!=d)f=0;
    	sum+=abs(a[i]);
	}
	if(f){
		m=m*2;
		for(int i=1;i<=n;i++){
			if(i*(i-1)*d>=m){
				ans=i;
				break;
			}
		}
		cout<<ans-1;
		return 0;
	}
	if(sum*2<=m){
		cout<<n;
		return 0;
	}
	ll m0=m;
	for(int i=2;i<=n;i++){
		m=m0;
		ll cnt=0;
		for(int j=i-1;j>=1;j--){
			if(m>=a[i]-a[j]){
				m=m-(a[i]-a[j]);
				cnt++;
			}else break;
		} 
		ans=max(ans,cnt);
	}
	cout<<ans+1;
	return 0;
}

