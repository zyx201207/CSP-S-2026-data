#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
ll cnt;
ll ans;
ll s;
bool cmp(ll x,ll y){
	return x<=y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++){
		if(a[i]<=a[i+1]){
			ans=a[i+1]-a[i];
			ll c=a[i+1]-a[i+2];
			ll b=a[i]-a[i+2];
			if(c<b){
				a[i]=a[i+1];
			}
			else{
				
				a[i+1]=a[i];
			}
			m=m-ans;
		}
			else if(a[i]>=a[i+1]){
				cnt=a[i]-a[i+1];
				ll d=a[i]-a[i+2];
				ll e=a[i+1]-a[i+2];
				if(d<e){
					a[i+1]=a[i];
				}
				else{
					
					a[i]=a[i+1];
				
				}
				m=m-cnt;
			}
			s++;
	if(m<=0){
		break;
	}
}
	cout<<s;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

