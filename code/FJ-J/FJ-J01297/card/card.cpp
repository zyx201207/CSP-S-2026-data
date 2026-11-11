#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	long long sum[m]={0};
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long l=1;l<=n;l++){
		long long p[n-l+1];
		if(l==n){
			sum[a[n-1]]++;
		}
		else{
			for(long long i=l-1;i<n-1;i++){
				bool t=0;
				if(i==0)
					p[0]=a[i];
				else{
					for(long long j=0;j<n-l+1-1;j++){
						if(p[j]==a[i]){
							for(long long k=j;k<n-l+1-1;k++){
								p[k]=0; 
							}
							p[j]=a[i];
							t=1;
						}
					}
					if(t==0)
						p[i]=a[i];
				}
			}
		}
	}
	return 0;
} 
