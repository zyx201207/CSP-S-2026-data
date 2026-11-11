#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[10000010],m,d[10000001],sum=0,maxa=-1;
bool cmp(ll x,ll y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	for(ll i=2;i<=n;i++){
		sum=0;
		for(ll j=i;j<=n;j++){
			ll k=d[j]*(j-i+1);
			if(sum+k<=m) sum+=k;
			else{
				maxa=max(maxa,j-i+1);
				break;
			} 
		}
	}
	cout<<maxa;
	
	return 0;
}
