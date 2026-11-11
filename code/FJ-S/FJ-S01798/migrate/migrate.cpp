#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int a[2000005];
int d=0;
int n=0;
int mj(int fr,int la){
	int dp[20000005][20000005];
	dp[fr][fr]=1;
	for(int i1=fr;i1<=la;i1++){
		for(int j1=d;j1>0;j1--){
			dp[fr][i1]+=dp[fr][i1-j1];
		}
	} 
	return dp[fr][la];
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=0;
	int t=0;
	cin>>c>>t;
	for(int q=0;q<t;q++){
		cin>>n>>d;
		int ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(mj(i,j)==2){
					ans++;
				} 
			} 
		} 
		cout<<ans<<endl;
		ans=0;
		for(int i=0;i<n;i++){
			a[i]=0;
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
