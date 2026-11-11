#include <bits/stdc++.h>
using namespace std;
long long a[500005],qzh[500005];
int flag;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	long long d=a[2]-a[1];
	for(int i=1;i<=n;i++){
		qzh[i]=a[i]+qzh[i-1];
		if(i>=2&&a[i]-a[i-1]!=d) flag=1;
	}
	if(flag==0){
		for(int i=n;i>=1;i--){
			if(a[1]*i+i*(i-1)*d/2+m>=a[i]*i){
				cout<<i;
				return 0;
			}
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n-i+1;j++){
			if(qzh[j+i-1]-qzh[j-1]+m>=a[j+i-1]*i){
				cout<<i;
				return 0;
			}
		}
	}
	return 0;
} 
