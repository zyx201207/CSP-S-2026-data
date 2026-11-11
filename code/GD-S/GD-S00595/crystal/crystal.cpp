#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define un unsigned

const int N=5e5+5;
ll n,a[N],ans=0,cha[N];
un ll m;
bool A=0,B=0;

void f1(ll k,ll mid){
	if(m>=k){
		m=m-k,ans++;
		k+=mid+1;
		f1(k,mid+1);
	}
	return ;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cha[i]=a[i]-a[i-1];
		if(a[i]!=i){
			A=1;		
		}
	}
	sort(a+1,a+n+1);
	for(int i=2;i<n;i++){
		if(cha[i]!=cha[i+1]){
			B=1;
		}
	}
	if(A==0){
		ll mid=1ll*(n*1.0/2+0.5),x=0;
		for(ll i=mid-1;i>0;i--){
			x=a[mid-i];
			if(m>=x){
				m=m-x,ans++;
			}
			else{
				break;
			}
		}
		ans++;
		ll k=mid+1;
		if(m>=k){
			f1(k,mid+1);
		}
		cout<<ans;
	}
	else if(B==0){
		ll x=0;
		for(ll i=n-1;i>0;i--){
			x=a[n]-a[i];
			if(m>=x){
				m=m-x,ans++;
			}
			else{
				break;
			}
		}
		ans++;
		cout<<ans;
	}
	else{
		ll k=m;
		for(ll j=2;j<=n;j++){
			ll ansj=0;
			for(ll i=j;i>1;i--){
				ll d=a[j]-a[i-1];
				if(d<=m){
					m=m-d;
					ansj++;
				}
			}
			ans=max(ansj,ans);
			m=k;
		}		
		ans++;
		cout<<ans;
	}
	return 0;
}
