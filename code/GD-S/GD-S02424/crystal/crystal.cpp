#include<bits/stdc++.h>
using namespace std;
long long n,m,sum1,a[500010],b[500010],s,xx=1,xx1=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) xx=0;
		if(i>2&&a[2]-a[1]!=a[i]-a[i-1]) xx1=0;
	}
	if(xx){
		if((n+1)*n/2<=m){
			cout<<n;
		}
		else{
			for(int i=1;i<=n;i++){
				sum1+=i;
				if(sum1>m){
					cout<<i;
					return 0;
				}
			}
		}
	}
	else if(xx1){
		if(n*(n-1)/2*(a[2]-a[1])<=m){
			cout<<n;
		}
		else{
			for(int i=1;i<=n;i++){
				sum1=sum1+i*(a[2]-a[1]);
				if(sum1>m){
					cout<<i;
					return 0;
				}
			}
		}
	}
	else{
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
			s=a[i]-a[i-1];
			b[i-1]=s+b[i-2];
		}
		for(int i=1;i<=n;i++){
			if(b[i]>m){
				cout<<i;
				return 0;
			}
		}
		cout<<n;
	}
}
