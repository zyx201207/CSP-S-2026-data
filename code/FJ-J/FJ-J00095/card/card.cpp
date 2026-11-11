#include<iostream>
using namespace std;
long long n,m; 
long long a[600000];
long long b[600000];
long long c[600000]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		long long t=0;
		for(long long j=i;j<=n;j++){
			long long m=t; 
			for(long long k=1;k<=t;k++){
				if(c[k]==a[j]){
					for(long long l=k;l<=t;l++){
						c[l]=0;  
					}
					t=k;
					c[t]=a[j];
					break;
				}
			}
			if(t==m){ 
				t++;
				c[t]=a[j];
			} 
		}
		for(long long j=1;j<=t;j++){
			b[c[j]]++;  
			c[j]=0;  
		}
	} 
	for(long long i=1;i<=m;i++){
		cout<<b[i]<<' ';  
	}
	return 0;
}
