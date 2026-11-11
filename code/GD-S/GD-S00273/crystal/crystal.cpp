#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],num,dp[5005][5005],cnt,l[50005];
struct edge{
	long long n,w;
}ex[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int jis=0;
	for(int i=n-1;i>=1;i--){
		if(a[i+1]==a[i] || a[i+1]-a[i]==ex[jis].w) ex[jis].n++;
		else  ex[++jis].w=a[i+1]-a[i],ex[jis].n=1;
		
	}
	if(jis==1){
		int num=m;
		for(int i=1;i<=n;i++){
			if(m-ex[1].w*i>=0){
				cnt++;
				m-=ex[1].w*i;
			}
			else{
				cout<<cnt+1;
				return 0;
			}
		}
	}
	l[0]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			
			if(l[j-1]+ex[j].w*(dp[i-1][j]+1)<=i){
				dp[i][j]=max(dp[i][j-1],max(dp[i-1][j],dp[i-ex[j].w*(ex[j-1].n+1)][j-1]+ex[j+1].n));
				l[j]=i;
			}
			else if(ex[j].w<=i){
				dp[i][j]=max(dp[i][j-1],max(ex[j+1].n+1,dp[i-1][j]));
				l[j]=i;
			}
			else{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
			
		}
	}
	cout<<dp[m][n]+1;
	return 0;
}
