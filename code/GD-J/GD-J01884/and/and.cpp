#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2*1e5+10;
ll a[N];
ll n,m,mx;
ll k(ll x){
	ll cnt=0;
	while(x){
		cnt+=x%2;
		x/=2;
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			mx=max(a[i],mx);
		}
		cout<<mx;
	}else if(m==n){
		mx=a[1];
		for(int i=1;i<=n;i++){
			mx=mx&a[i];
		}
		cout<<mx;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
	}else{
		int s=1,mn=1e8;
		for(int i=1;i<=n;i++){
			if(k(a[i])<mn){
				mn=k(a[i]);
				s=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(s!=i)mx&=a[i];
		}
		cout<<mx;
	}
	return 0;
} 
