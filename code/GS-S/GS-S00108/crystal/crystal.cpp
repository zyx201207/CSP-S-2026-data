#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal,in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,c=0;
	long long a[159890];
	long long d=n/2;
	long long b[159890];
	long z=0;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0;i<n;i++){
		b[i]=abs(a[n/2+1]-a[i]);
	}
	sort(b,b+n);
	for(long long i=0;i<n;i++){
		if(c<m){
			c=c+b[i];
			z++;
		}
		else{
			cout<<z;
			return 0;
		}
	}
	
	return 0;
}

