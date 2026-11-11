#include<bits/stdc++.h>
using namespace std;
int n,m,a[50010],dp[50010],dp1[50010];
void cha(int a1,int b1){
	for(int i=a1;i<b1;i++){
		if(a[i]==a[b1]){
			for(int j=a[i];j<a[b1];j++){
				dp[j]=1;
			}
		}
	}
} 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[j]=0;
		}
		for(int j=i;j<=n;j++){
			cha(i,j);
		}
		for(int j=i;j<=n;j++){
			if(dp[j]!=1){
				dp1[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<dp1[i]<<' ';
	}
	return 0;
}

