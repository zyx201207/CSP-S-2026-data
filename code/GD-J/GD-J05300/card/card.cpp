#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	long long x=0;
	cin>>n>>m;
	long long a[n+24]={0},b[n+24]={0},c[m+21]={0};
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=i;j<n;j++){//1¾Ö 
			x=-1;
			for(long long k=0;k<j-i;k++){
				if(b[k]==a[j]){
					x=k;
				}
			}
			if(x==-1){
				b[j-i]=a[j];
				
			}
			else{
				for(long long k=x;k<j-i;k++){
					b[k]=-1;
				
				}
				b[j-i]=a[j];
			}
		
		}
		for(long long j=i;j<n;j++){
			
			if(b[j-i]>0)c[b[j-i]]+=1;
		}
		
		
	}
	for(long long i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}

	return 0;
} 

