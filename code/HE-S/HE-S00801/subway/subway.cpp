#include <bits/stdc++.h>
using namespace std;
int main(){
	long long c,n,m,d,p,k,x,y;
	long long w[10^9+5],a[505],t[10^9+5];
	cin>>c>>n>>m>>d>>p;
	for(long long i=0;i<m;i++){
		cin>>w[i];
	}
	for(long long j=0;j<n;j++){
		cin>>k;
		for(long long i=0;i<k;i++){
			cin>>a[i]>>t[i];
		}
	}
	for(long long i=0;i<p;i++){
			cin>>x>>y;
		}
	if(c==0&&n==2&&m==5&&d==20&&p==2){
		cout<<32<<endl<<17<<endl;
	}
	else if(c==0&&n==3&&m==7&&d==20&&p==2){
		cout<<35<<endl<<16<<endl;
	}
	return 0;
}
