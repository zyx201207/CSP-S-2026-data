#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200007],b[200007],sum[200007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=j;k++){
				if(a[j]!=b[k]){
					b[k]=a[j];
					sum[b[k]]++;
				}
				else{
					for(int l=k;l<=j-1;l++){
						b[l]=0;
						sum[l]=0;
					}
					b[k]=a[j];
					sum[b[k]]++;
				}
			}
		}
	}
	for(int i=1;i<=n-1;i++){
		cout<<sum[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
