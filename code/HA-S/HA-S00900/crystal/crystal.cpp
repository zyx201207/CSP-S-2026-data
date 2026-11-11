#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,m;


int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	ll a[n+3]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	ll b[n+3]={0};
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
//		cout<<b[i]<<' '<<a[i+1]<<' '<<a[i]<<'\n';
	}
	
	ll t=0;
	ll j=1;
	while(t<=m){
		t+=b[j]*j;
		j++;
	}
	cout<<j-1;
	
	return 0;
}
