#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[50005],sum[50005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long b[50005];
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			for(int k=i;k<j;k++){
				if(b[j]==b[k]){
					for(int g=k;g<j;g++){
						b[g]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			sum[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
