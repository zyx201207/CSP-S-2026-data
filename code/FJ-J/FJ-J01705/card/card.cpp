#include<bits/stdc++.h>
using namespace std;
const int MAXM=3005,MAXN=2e5+5;

int n,m;
int a[MAXN];
//bool sum[MAXN][MAXM];
int endn[MAXN];
int ans[MAXM];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool sum[n+1][m+1];
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		endn[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		int k=endn[a[i]];
		for(int j=1;j<=m;j++){
			sum[i][j]=sum[k+1][j];
		}
		sum[i][a[i]]=1;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			ans[i]+=sum[j][i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
	
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
