#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string e;
ll q;
 hh(ll a){
	a--;	
	q=a/2;	
	ll cnt=0;
	for(int i=1;i<=q;i++){
		if(e[i]!=e[a+1-i]) cnt++;
		
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,a,c[200005],sum=1,S;
	char b,d[200005];
	bool p=0;
	cin>>n;
	for(int i=1;i<=n;i++){		
		cin>>a>>b;
		c[i]=a;
		d[i]=b;		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=c[i];j++,sum++){
			e[sum]=d[i];
		}
		S=sum;
	}
	sum=1;
	cout<<hh(S);
	
	return 0;	
} 
