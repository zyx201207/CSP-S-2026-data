#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll>a(n+1);
	bool pA=true,pB=true;
	for(ll i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=i) pA=false;
		if(i>1 && !(a[i]-a[i-1] == a[2]-a[1])) pB=false;
	}

	ll cnt=1;
	if(pA){
		int i=1;
		while(m>=i) {
			m-=i;
			i++;
			cnt++;
		}
		cout<<cnt;
	}else if(pB){
		int p=abs(a[2]-a[1]);
		int i=p;
		while(m>=i) {
			m-=i;
			i+=p;
			cnt++;
		}
		cout<<cnt;
	}
	else{
		vector<ll>z(n+1);
		vector<ll>d(n+1);
		sort(a.begin(),a.end());
		d[1]=0;
		for(int i=1;i<=n;i++){
			z[i]=a[i]-a[i-1];
			if(i>1){
				d[i]=d[i-1]+z[i]*(i-1);
			}	
		}
		
		ll l=1,sum=0;
		for(ll r=1;r<=n;r++){
			if(!(m>=z[r]*(r-l))){
				while(m<z[r]*(r-l) && l<=r){
					m+=sum;
					sum-=z[l];
					l++;
				}
			}
			if(l<=r){
				m-=z[r]*(r-l);
				cnt=max(cnt,r-l+1);
				sum+=z[r];
			}else break;
		}
		cout<<cnt;
	}
	
	return 0;
} 
