#include <bits/stdc++.h>
using namespace std;
int t,c,n;
long long d;
long long x[2000001]={};
long long sum[2000001]={};
int s=0;
int k=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		cin>>x[1];
		for(int j=2;j<=n;j++){
			cin>>x[j];
			sum[j]=sum[j-1]+x[j]-x[j-1];
			int l=1,r=j-1;
			while(l<r){
				int mid=(l+r)/2;
				if(sum[j]-sum[mid]>=2*d){
					l=mid+1;
				}
				else if(sum[j]-sum[mid]<=2*d){
					r=mid;
				}
			}
			l=r;
			for(int mid=l+1;mid<j;mid++){
				if(sum[mid]-sum[l]<=d&&sum[j]-sum[mid]<=d){
					s++;
				}
			}
			if(s==2){
				k++;
			}
			s=0;
		}
		cout<<k<<endl;
		k=0;
	}
	return 0;
} 
