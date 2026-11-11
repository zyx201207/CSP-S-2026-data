#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int dp[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int s[10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<5&&m<2){
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++)s[k]=0;
			if(a[i]!=a[i+1]) s[i]=a[i];
			for(int j=1;j<=n;j++){
				if(s[j]!=0)dp[j]++;
			}
			
		}
	}
	for(int i=1;i<=n;i++){
		if(dp[i]!=0){
			cout<<dp[i]<<' ';
		}
	}
	return 0;
}
