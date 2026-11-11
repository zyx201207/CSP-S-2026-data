#include<bits/stdc++.h>
using namespace std;
int a[500002];
int num[300002];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int dp[500002];
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k;
	for(int x=1;x<=n;x++){
		for(int i=1;i<=n;i++){
			dp[i]=0;
		}
		k=x;
		for(int i=x;i<=n;i++){
			for(int j=x;j<=i;j++){
				if(dp[j]==a[i]){
					k=j;
					for(int dp1=j;dp1<=i;dp1++){
						dp[dp1]=0;
					}
				}
			}
			dp[k]=a[i];
			k++;
		}
		for(int i=1;i<=n;i++){
			if(dp[i]!=0){
				num[dp[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<' ';
	}
	return 0;
} 
