#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],temp[500001],ans[300001],sum=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++){
		sum=1;
		for(long long j=i;j<=n;j++){
			for(long long x=1;x<=sum;x++){
				if(a[j]==temp[x]){
					for(long long y=x;y<=sum;y++) temp[y]==0;
					sum=x+1;
					temp[sum-1]=a[j];
					break;
				}
				if(x==sum){
					temp[sum]=a[j];
					sum++;
					break;
				}
			}
		}
		for(long long j=1;j<sum;j++){
			ans[temp[j]]++;
			temp[j]=0;
		}
	}
	for(long long i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
