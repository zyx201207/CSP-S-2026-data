#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long N=2e8+5;
const long long M=2e14+5;
ll n;
ll a[N];
char b[N],c[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll cnt=0,len=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		len+=a[i];
	}
	ll x=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			c[x]=b[i];
			x++;
		}
	}
	ll l,r;
	if(len%2 == 0){
		l=len/2;
		r=l+1;
	}else{
		l=(len-1)/2;
		r=l+2;
	}
	while(l != 0){
		if(c[l] != c[r]){
			cnt++;
		}
		l-=1;
		r+=1;
	}
	cout<<cnt;
	return 0;
}
