#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N=5e5;

ll n,m;
ll a[N+10];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	ll ans=1,tot=0;
	
	for(ll l=1,r=1;r<=n;r++){
		tot+=a[r];
		while(a[r]*(r-l+1)-tot>m){
			tot-=a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	
	cout<<ans;
	
	return 0;
}
