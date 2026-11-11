#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a[101]={};
	int b[101]={};
	int n,m;
	cin>>n>>m;
	int dp[101][101]={};
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		for (int l=0;l<n;l++){
			dp[i][l]=-1;
		}
	}
	for (int i=0;i<n;i++){
		for (int l=i;l<n;l++){
			for (int p=i;p<l;p++){
				if (dp[i][p]==a[l]){
					for (int u=p;u<l;u++){
						dp[i][u]=-1;
					}
				}
			}
			dp[i][l]=a[l];
		}
	}
	for (int i=1;i<n;i++){
		for (int o=0;o<n;o++){
			
			for (int l=0;l<n;l++){
				if (dp[o][l]==i){
					b[i]++;
					continue;
				}
			}
		}
	}
	for (int i=0;i<n;i++){
		if (b[i]!=0){
			cout<<b[i]<<' ';
		}
	}
	cout<<"\n";
	return 0;
}
