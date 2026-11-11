//GZ-J00529 李博洋 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000],sum,z[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(long long j=1;j<=n;j++){
	for(long long i=1;i<=n;i++){
		if(a[i]<a[i+1])
		swap(a[i],a[i+1]);
	}	
	}
cout<<a[1];
	
	return 0;
}
