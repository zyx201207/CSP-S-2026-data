#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,a[200000+10],pd=1,s;
	char c,ch;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c;
		s=a[i];
		if(i==1)ch=c;
		else{
			if(ch==c)pd+=1;
			else pd-=100000;
		}
	}if(pd==n){
		cout<<0;
		return 0;
	}if(n%2==0){
		cout<<n*s/2;
		return 0;
	}cout<<1;
	return 0;
}
