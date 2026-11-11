#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2*1e5;
ll a[N];
string s;
bool Canbe(ll n){
	n++;
	for(int i=1;i<=30;i++){
		if(pow(2,i)==n) return 1;
	}
	return 0;
}
int main(){
	bool f=1;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) {cin>>a[i];f=Canbe(a[i]);}
	sort(a,a+n); 
	if(m==1) cout<<a[n-1];
	else{
		if(m==2){
			ll maxn=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(i!=j) {
						maxn=max(a[i]&a[j],maxn);
					}
				}
			}
			cout<<maxn;
		}
		if(m==n){
			ll cnt=a[0];
			for(int i=0;i<n;i++) cnt=cnt&a[i];
			cout<<cnt;
		}
		if(f)
		{	ll cnt=a[n-1];
			for(int i=n-1;i>=n-1-m;i--) cnt=cnt&a[i];
			cout<<cnt;
		}
	}
	return 0;
}
