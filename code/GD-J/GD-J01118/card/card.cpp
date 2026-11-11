#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
const int maxn2=1e5+10;
int a[maxn][maxn];
int a1[maxn]; 
int dp[maxn];
int n,m;
int nd(int x){
	if(x!=n){
		return 1;
	}else{
		return 0; 
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a1[i];
	} 
	for(int i=n; i>=1; i--){
		a[i][a1[i]]=a[i+nd(i)][a1[i]]+1;
		for(int j=1; j<=m; j++){
			if(a[i][j]%2==1){
				dp[j]++;
			}
		}
	} 
	for(int i=1; i<=m; i++){
		cout<<dp[i]<<" ";
	}
	return 0;
} 

