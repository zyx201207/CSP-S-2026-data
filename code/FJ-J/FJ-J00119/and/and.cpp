#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],k,s=1e9,z;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		k+=a[i];
	}
	k/=n;
	if(m==1){
		for(long long i=1;i<=n;i++)
			z=max(z,a[i]);
	} 
	else{ 
	   for(long long i=1;i<=n;i++){
		if(s>=abs(a[i]-k))z=a[i];
	  }
	}
	cout<<z;
	return 0;
} 
