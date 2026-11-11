#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll a[500010],b[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	int d=b[2]-b[1];
	bool isb=1;
	for(int i=3; i<=n; i++){
		if(b[i]-b[i-1]!=d) isb=0;
	}
	if(isb){
		for(int i=1; i<=n; i++){
			a[i]=b[n]-b[i];
		}
		ll cnt=0;
		for(int i=n; i>=1; i--){
			if(m>=a[i]){
				cnt++;
				m-=a[i];
			}
			else break;
		}
		cout<<cnt;
		return 0;
	}
	else {
		ll mm=m;
		ll maxn=-1;
		for(int k=1; k<=n; k++){
			m=mm;
			for(int i=1; i<=k; i++){
				a[i]=b[k]-b[i];
			}
			ll cnt=0;
			for(int i=k; i>=1; i--){
				if(m>=a[i]){
					cnt++;
					m-=a[i];
				}
				else break;
			}
			maxn=max(maxn,cnt);
		}
		cout<<maxn;
	}
	return 0;
}
