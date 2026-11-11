#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
const int M=3e5;
bool lastIsKilled[M+1];
int dp[2][M+1];
int a[N+1];
int lastId[M+1];
bool notFirst[M+1];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			if(dp[((i+1)&1)][j]==0&&j!=a[i]){
				dp[(i&1)][j]=dp[((i+1)&1)][j];
			}
			else if(notFirst[a[i]]&&lastId[a[i]]>lastId[j]){
				dp[(i&1)][j]=dp[((i+1)&1)][j];
			}
			else{
				dp[(i&1)][j]=dp[((i+1)&1)][j]+1;
			}
			cerr<<dp[i&1][j]<<" ";
		}
		cerr<<endl;
		lastId[a[i]]=i;
		notFirst[a[i]]=true;
	}
	for(int i=1;i<=m;i++){
		cout<<dp[1][i]<<" ";
		cerr<<dp[1][i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
