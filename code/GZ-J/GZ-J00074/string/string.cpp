//×¼¿¼Ö¤ºÅ£ºGZ-J00074 ÐÕÃû£ººú¾þºÀ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
char c[N];
string sz="",sf="";
ll n,a[N],ans=0,ji=0,sumn=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ji+=a[i];
		if(ji<1e8){
			for(ll j=1;j<=a[i];j++){
				sz+=c[i];
				sumn++;
			}
		}
	}if(ji<1e8){
		for(ll i=n;i>=1;i--){
			for(ll j=1;j<=a[i];j++){
				sf+=c[i];
			}
		}
		for(ll i=0;i<sumn;i++){
			if(sz[i]!=sf[i]){
				ans++;
			}
		}
	}else{
		ans=ji;
	}
	ans/=2;
	cout<<ans;
	return 0;
}
