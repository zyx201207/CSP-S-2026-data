#include<bits/stdc++.h>
using namespace std;
long long a,d=0,n=0,m,l,p;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>> n>>m;
	long long b[n+5],c[10000];
	for(long long i=0;i<n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n);
	for(long long j=m-1;j<n;j++){
		c[l]=(b[j-1]&b[j]);
		p=max(p,c[l]);
		l++;
	}cout<<p;
	return 0;
}
