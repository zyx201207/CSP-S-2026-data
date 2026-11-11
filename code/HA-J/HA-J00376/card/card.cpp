#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,a[450001]={0},b[5001]={0},sum1[5001]={0},c=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		long long sum[5001]={0};
		for(long long j=i;j<=n;j++){
			b[j-c]=a[j];
			sum[a[j]]++;
			if(sum[a[j]]>1){
				for(long long k=j-c-1;k>0;k--){
					sum[b[j-c]]=0;
					if(b[j-c]==b[k]){
						c=j-k;
						break;
					}
				}
			}
		}
		for(long long i=1;i<n;i++){
			sum1[b[i]]++;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<sum1[i]<<" ";
	}
	return 0;
}
