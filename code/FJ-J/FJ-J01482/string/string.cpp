#include<bits/stdc++.h>
using namespace std;
long long n;
long long t[212345],num[212345],maxn;
long long o=0,a[212345];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char x;
		cin>>num[i]>>x;
		o=max(o,num[i]);
		t[i]=int(x);
	} 
	bool g=0;
	for(int i=1;i<=n;i++){
		if(num[i]!=num[n-i+1]&&t[i]!=t[n-i+1]) o=1;
	}
	if(o==0) cout<<0;
	else if(o<=50){ 
		int k=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=num[i];j++){
				a[++k]=t[i]-97;
			}
		}
		for(int i=1;i<=k/2+k%2;i++){
			if(a[i]!=a[k-i+1]) maxn++;
		}
		cout<<maxn;
	}
	else{
		long long g=num[1];
		for(int i=1;i<=n;i++) g=__gcd(g,num[i]);
		for(int i=1;i<=n;i++) num[i]/=g;
		int k=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=num[i];j++){
				a[++k]=t[i]-97;
			}
		}
		for(int i=1;i<=k/2+k%2;i++){
			if(a[i]!=a[k-i+1]) maxn++;
		}
		cout<<maxn*g;
	}
	return 0;
} 
