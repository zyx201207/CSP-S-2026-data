#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i]; 
	}
	if(n==1){
		cout<<"0";
		return 0;
	} 
	ll t=0,sum=a[1];
	for(ll i=1;i<n;i++){
		if(c[i]==c[i+1])t++;
	}
	if(t==n-1){
		cout<<"0";
		return 0;
	}
	t=0;
	for(ll i=1;i<n;i++){
		if(a[i]==a[i+1])t++;
		sum+=a[i+1];
	}
	if(t==n-1)cout<<a[1]*n/2;
	else cout<<sum/2-sum/52;
	return 0;
}
