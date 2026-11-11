#include<bits/stdc++.h>
using namespace std;
int a[500001],dp[5001][5001],sum=0,flag=0,MAX=INT_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
			dp[i][j]=a[j]-a[i];
			}
		}
		for(int j=1;j<=n;j++){
			for(int i=1;i<j;i++){
				flag=0;
				sum=1;
				for(int k=i;k<=j;k++){
					if(flag>m)break;
					if(MAX<sum){
						MAX=sum; 
					}
					flag+=dp[k][j];
					sum++;
				}
			}
		}
	}
	cout<<MAX;
	return 0;
} 
