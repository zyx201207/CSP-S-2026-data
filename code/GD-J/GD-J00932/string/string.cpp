#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
char a[2000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll num=1;
	for(int i=1;i<=n;i++){
		ll x;
		char y;
		cin>>x>>y;
		for(int i=1;i<=x;i++){
			a[num]=y;
			num++;
		}
	}
	ll ans=0;
	ll l=1,r=num-1;
	while(l<=r){
		if(a[l]!=a[r]) ans++;
		r--,l++; 
	}
	cout<<ans;
} 
