#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	long long c[a+1];
	for(long long i=1;i<=a;i++){
		cin>>c[i];
	}
	long long x[b+1];
	for(long long i=1;i<=b;i++){
		x[i]=0;
	}
	for(long long i=1;i<=a;i++){
		long long m[a+1];
		for(long long j=1;j<=a;j++){
			m[j]=0;
			if(j>=i){
				m[j]=1;
			}
		}
		for(long long j=i;j<=a;j++){
			for(long long z=i;z<j;z++){
				if(c[j]==c[z]){
					if(m[z]==1){
						for(long long h=z;h<j;h++){
							m[h]=0;
						}
					}
					
				}
			}
		}
		for(long long j=1;j<=b;j++){
			for(long long z=1;z<=a;z++){
				if(c[z]==j){
					if(m[z]>0){
						x[j]++;
					}
				}
			}
		}
	}
	for(long long i=1;i<=b;i++){
		cout<<x[i]<<" ";
	}
	return 0;
}
