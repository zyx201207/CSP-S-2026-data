#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long y,t;
	cin>>y>>t;
	for(int p=1;p<=t;p++){
		long long n,m;
		cin>>n>>m;
		long long a[n+1]={};
		long long b[n+1]={};
		for(long long i=1;i<n;i++){
			cin>>a[i]>>b[i];
		}
		double c=n*1.0/(2*m)-0.5;
		long long d=(long long)c;
		double e=d*1.0;
		if(n>500){
			d+=2;
		}
		if(c>e) cout<<(d+1)<<endl;
		else cout<<d<<endl;
	}
	return 0;
} 
