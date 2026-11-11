#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[2000000];
long long c=0,d=0,f=0;
char b[10000000],e[10000000];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int j=n;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
		d=d+a[i];
	}
	for(long long i=0;i<=n;++i){
		if(b[i]==b[i+1]){
			c=c+1;
		}
		
	}
	if(c==n){
		
		cout<<0;
		
	}
	else if(d%2!=0){
		cout<<d/2;
	}
	else if(d%2==0){
		cout<<2;
	}
	return 0;
}
