#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200010];
char b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,sum=0,ans=0,sum2=0;
	ll cnt=0;
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll x;
		char c;
		cin>>x>>c;
		if(c==b[cnt]) a[cnt]+=x;
		else{
			cnt++;
			a[cnt]=x;
			b[cnt]=c;
		}
		sum+=x;
	}ll r=cnt;
	for(ll i=1;i<=cnt;i++){
		ll target; 
		if(a[i]+sum2>sum/2){
			target=sum/2-sum2;
			while(a[r]<target){
				if(b[r]!=b[i]) ans+=a[r];
				target-=a[r];
				a[r]=0;
				r--;
			}if(b[i]!=b[r]) ans+=target;
			break;
		}else{
			target=a[i];
			while(a[r]<target){
				if(b[r]!=b[i]) ans+=a[r];
				target-=a[r];
				a[r]=0;
				r--;
			}
			if(b[i]!=b[r]) ans+=target;
			a[r]-=target;
		}
		sum2+=a[i];
	}cout<<ans;
	return 0;
}
