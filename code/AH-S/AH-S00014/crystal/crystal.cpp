#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
bool f=1;
ll cnt=1;
ll sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)f=0;
	}
	sort(a+1,a+1+n);
	ll p=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=p){
			f=0;
		}
	}
	if(f){
		ll k=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(m>=i*k){
				cnt++;
				m-=(i*k);
			}
		}
		cout<<cnt;
		return 0;
	}
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;i++){
		if(m>=sum[i]){
			cnt++;
			m-=sum[i];                                                 
		}
	}
	cout<<cnt;
	return 0;
}
