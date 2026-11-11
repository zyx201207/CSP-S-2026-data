//GZ-J00401 ³ÌÐÞÆë 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	ll ans=0,last=1;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		if(last!=x)cout<<i<<' ',last++; 
	}
	cout<<n;
}
