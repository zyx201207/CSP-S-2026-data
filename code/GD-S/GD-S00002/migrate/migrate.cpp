#include<bits/stdc++.h>
#include<vector>
using namespace std;
const int MAXN = 1e6;
vector<int> dp(MAXN);
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c,d,e,f; cin>>a>>b;
	for(int i=1;i<=b;i++){
		cin>>c>>d;
		for(int i=1;i<=c;i++){
			cin>>dp[i];
		}
	}
	dp[1]=0;
	for(int i=2;i<=b;i++){
		dp[i] = (i*2)*(dp[i-1]+dp[i-2]);
	}
	cout<<dp[b]<<endl;
	cout<<(dp[b])+1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
