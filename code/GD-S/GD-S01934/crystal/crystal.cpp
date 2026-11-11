#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[50500];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ll ans=0,flg,al;
	for(int i=0;i<n;i++){
		flg=m;ans=0;
		for(int j=i;j>=0;j--){
			if(flg>=a[i]-a[j]){
				ans++;
				flg-=a[i]-a[j];
			}
			else{
				if(ans>al){
					al=ans;
					break;
				}
				else{
					printf("%lld ",al);
					return 0;
				}
			}
		}
	}

	printf("%lld",ans);
	return 0;
}
