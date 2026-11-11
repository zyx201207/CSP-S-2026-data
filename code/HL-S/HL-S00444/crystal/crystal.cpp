#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ll he=2,ta=1,len=0,num=0;
	ll ma=1;
	for(he;he<=n;he++){
		len=he-ta;
		num+=len*(a[he]-a[he-1]);
		len++;
		while(num>m){
			num-=a[he]-a[ta];
			ta++;
		}
		len=he-ta+1;
		if(len>ma) ma=len;
	}
	cout<<ma;
	return 0;
}
