#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500010]; 
ll tmp=0;
ll ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll flag=0;
	for(ll i=1;i<=n;i++){
		ll cnt=tmp;
		cin>>a[i];
		tmp=a[i]-a[i-1];
		if(i>=3&&tmp==cnt){
			flag=1;
		}else{
			flag=0;
		}
	}
	ll cnt=(a[n]-a[1])/(n-1);
	ll tmp1=0;
	ll mm=m;
	if(flag){
		while(1){
			mm-=(++tmp1)*cnt;
			if(mm>=0){
				ans++;
			}else{
				break;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
