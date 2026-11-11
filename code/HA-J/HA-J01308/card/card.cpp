#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],sum[m+1],b[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		sum[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
		for(int j=i;j<=n;j++){
			for(int k=1;k<=j;k++){
				if(b[k]==b[j]){
					for(int p=k;p<j;p++){
						b[p]=0;
					}
				}
			}
			if(b[j]==i){
				sum[i]++;
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
