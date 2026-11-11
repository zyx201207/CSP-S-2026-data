#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n],b[m]{};
	for(long long i=0;i<n;i++) cin>>a[i];
	for(long long i=0;i<n;i++){
		long long c[n]{},d[n];
		for(long long j=i;j<n;j++) d[j]=a[j];
		for(long long j=i;j<n;j++){
			if(c[j]!=0){
				for(long long k=j+1;k<n;k++){
					d[i]=-1;
				}
			}else c[j]=1;
		}
		for(long long j=0;j<n;j++){
			for(long long k=j;k<m;k++){
				if(a[j]==k+1) b[j]++;
			}
		}
	}
	for(long long i=0;i<m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
