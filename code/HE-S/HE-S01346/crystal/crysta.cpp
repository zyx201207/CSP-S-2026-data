#include <bits/stdc++.h>
using namespace std;
long long n,m,a[50009],b[50009],p,z,j,k,q,s;
int main(){
	freopen("crysta.in","r",stdin);
	freopen("crysta.out","w",stdout);
	cin>>n>>m;
	q=1;
	s=n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	j/=2;
	if(n%2) j++;
	else{
		if(a[j]-a[j-1]<a[j+2]-a[j+1]) j++;
		}
	if(a[j]-a[1]>a[n]-a[j]){
		j=1;
		k++;
	}
	for(long long i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(long long i=1;i<=n;i++){
		if(p+b[i]<m) {
			p+=b[i];
			z++;
		}
		
	}cout<<z;
	return 0;
}
