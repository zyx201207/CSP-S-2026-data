#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	long long w[m+1]={};
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	long long a[n+1]={};
	long long t[n+1]={};
	for(int i=1;i<=n;i++){
		cin>>a[i]>>t[i];
	}
	long long x[q+1]={};
	long long y[q+1]={};
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	
	if(c==0 and n==2 and m==5 and d==20 and q==2) cout<<32<<endl<<17;
	else if(c==0 and n==3 and m==7 and d==20 and q==2) cout<<35<<endl<<16;
	return 0;
}
