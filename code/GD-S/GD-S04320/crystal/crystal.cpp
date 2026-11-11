#include<bits/stdc++.h>
#define ll long long
#define N 500100
using namespace std;
int n;
ll m;
ll a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll cnt=0,ans=1;
	for(ll i=2;i<=n;i++){
		b[i]=b[i-1]+(a[i]-a[i-1])*(i-cnt-1);
		if(b[i]>m){
			ll ctn=0,ab=0;
			while((a[i-1]*ctn-ab)<b[i]-(a[i-1]*ctn-ab)-m){
				cnt++;ctn++;
				ab+=a[cnt];
			}
			if(ctn<=i-cnt-1){
				b[i]-=(a[i-1]*ctn-ab);
				ans=max(ans,i-cnt);
			}
		}
		else ans=max(ans,i-cnt);
	}
	cout<<ans;
	return 0;
}
