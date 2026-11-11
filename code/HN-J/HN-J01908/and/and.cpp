#include<bits/stdc++.h>
using namespace std;
int pd(int a,int b,int popo){
	int zz=0;
	if(a==1 || b==1){
		return pow(10,popo);
	}
	if(a%2!=0 && b%2!=0){
		zz=pow(10,popo);
	}
	return pd(a/2,b/2,popo+1)+zz;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	long long n,m,a[200014];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	if(n==m){
		long long z=a[1];
		for(int i=2;i<=n;i++){
			z=pd(z,a[i],0);
		}
		cout<<z;
		return 0;
	}
	else{
		cout<<a[n-m+1];
		return 0;
	}
	return 0; 
}
