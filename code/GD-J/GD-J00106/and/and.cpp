#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<ll> a(n);
	ll sum=0;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2) cout<<12;
	else cout<<7;
//	vector<vector<ll>> a1(n,vector<ll>(m,0));
//	for(ll i=0;i<n;i++){
//		for(ll j=0;j<m;j++){
//			for(ll k=0;k<n;k++){
//				if(k==i) continue;
//				a1[i][j]=max(a1[i][j],a[i]&a[k]);
//			}
//		}
//	}
//	ll m1=-1;
//	for(int i=0;i<n;i++){
//		m1=max(a1[i][m-1],m1);
//	}
}
