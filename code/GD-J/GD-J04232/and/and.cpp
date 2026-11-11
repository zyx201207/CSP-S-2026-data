#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5,MAXN2=25;
int dp[MAXN2][MAXN2],a[MAXN],s[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=max(ans,a[i]);
		}
		cout<<ans;
	} 
	else if(m==2&&n<=2000){
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans;
	} 
	else if(m==n){
		cin>>a[1];
		int ans=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			ans&=a[i]; 
		}
		cout<<ans;
	}
	else if(n<=20){
		for(int i=1;i<=n;i++){
       		cin>>a[i];
        	dp[i][1]=max(dp[i-1][1],a[i]);
		}
   	 	for(int i=1;i<=n;i++){
     	   for(int j=1;j<=min(i,m);j++){
      	      dp[i][j]=max(dp[i][j],max(dp[i-1][j-1]&a[i],dp[i-1][j]));
    		}
 	  	}
    	cout<<dp[n][m];
	}
	else{
		bool A=true,B=true;
		int ansa_cnt=30,ansa=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			int cnt=0,tmp=a[i];
			while(tmp){
				tmp=tmp>>1;
				cnt++;
			}
			if(__builtin_popcount(a[i])!=cnt)A=false;
			if(cnt<ansa_cnt){
				ansa_cnt=cnt;
				ansa=a[i];
			}
			if(a[i]!=i-1)B=false;
		}
		if(A){
			cout<<ansa;
		}
		else if(B){
			int ans=a[n];
			for(int i=n-1;i>=n-m+1;i--)
				ans&=a[i];
			cout<<ans;
		}
		else{
			sort(a+1,a+n+1);
			int ans=a[n];
			for(int i=n-1;i>=n-m+1;i--)
				ans&=a[i];
			cout<<ans;
		}
	}
}
