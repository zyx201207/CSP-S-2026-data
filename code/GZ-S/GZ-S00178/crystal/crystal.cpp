//GZ-S00178 贵阳市第一中学 申智美
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	long long k=1,sum=0;
	long long x=a[1];
	for(long long i=2;i<=n;i++){
		int data=a[i]-x;
		if(data*k<=m){
			m-=data*k;
			for(long long j=1;j<=i;j++) a[j]=a[i];
			k++;
			x=a[i];
		}
		else if(data*k<=m){
			long long now=m/data;
			if(now==0){
				m=0;
				break;
			}
			else{
				for(long long j=1;j<=now;j++) a[j]=a[i];
				m=0;
			 }
			
		}
		if(m==0){
			break;
		}
	}
	long long i;
	for(i=1;i<=n;i++){
		if(a[i]!=a[i+1])  break;
	}
	cout<<i;
	return 0;
}









