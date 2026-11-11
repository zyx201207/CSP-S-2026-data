#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[500001],sum[500001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=0;
		}
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			for(int k=i;k<=j;k++){
				if(b[k]==b[j]){
					for(int l=k+1;l<=j;l++){
						b[l]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(b[j]>0){
				sum[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
