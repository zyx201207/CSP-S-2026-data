#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
const int N=5e5+10;
ll sum=0,s=0,c;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		s=a[i];
	}
		sort(a+1,a+n+1);
	ll l=1,r=s;
	for(ll i=1;i<=m;i++){

	c=(a[r]-a[l])/2;
		if(a[l]<c){
	
		sum++;
		
		}
		else break;
		}
	cout<<sum;
	return 0;
}
