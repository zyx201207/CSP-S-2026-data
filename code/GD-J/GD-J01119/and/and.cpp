#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[200005],b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	ll max0=-1;
	for(int i=0;i<n;i++){
		for(int k=0;k<n;k++){
			a[k]=b[k];
		}
		ll m_=m-1;
		ll ans=a[i];
		ll cnt=0;
		a[i]=0;
		while(m_--){
			ll max_=-1,t;
			for(int j=0;j<i;j++){
				ll asda=ans&a[j];
					if(max_<asda){
						max_=asda;
						t=j;
				}
			}
			a[t]=0;
			cnt++;
			ans=max_;
		}
		max0=max(max0,ans);
	}
	cout<<max0;
	return 0;
}
