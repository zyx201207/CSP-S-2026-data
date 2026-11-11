#include<bits/stdc++.h>
using namespace std;
int dp[200005][200005];
int a[200005];
int pd[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int lm=0,lml=0,tm=0,tml=0;//last_max,last_max_line,this_max,this_max_line
	for(int j=1;j<=n;j++){
		dp[1][j]=a[j];
		if(a[j]>lm){
			lm=a[j];
			pd[lml]=0;
			lml=j;
			pd[j]=1;
		}
	}
	for(int i=2;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(pd[j]==0){
				dp[i][j]=max(tm,lm&a[j]);
			}
			else{
				dp[i][j]=0;
			} 
			if(dp[i][j]>tm){
				tm=dp[i][j];
				pd[tml]=0;
				tml=j;
				pd[j]=1;
				
			}
		}
		lm=tm;
		lml=tml;
		tm=0;
		tml=0;
	}

	cout<<lm;
	return 0;
}
