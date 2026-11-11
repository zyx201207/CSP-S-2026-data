#include<bits/stdc++.h>//&
#define int long long
#define endl '\n'
using namespace std;
int a[20005],dp[2005][2005][60];
int n,m;/*
int o(int x){
	int ans=0;
	while(x!=0){
		if(x%2==1){
			ans++;
		}
		x>>=1;
	}
	return ans;
}
int dfs(int i,bool p,int step){
	int ans;
	if(step<=m){
		dfs(i+1,1,step+1);
		
	}
}*/
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int tm=-0x3f3f3f;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tm=max(a[i],tm);
	}
	if(m==1){
		cout<<tm;
	    return 0;
	}
	if(m==2){
		int mx=-0x3f3f3f;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					mx=max(mx,a[i]&a[j]);
				}
			}
		}
		cout<<mx;
		return 0;
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			int mx=-0x3f3f3f;
			for(int p=i;p>=1;p--)mx=max(a[p],mx);
			dp[i][j][1]=mx;
		}
	}
	for(int k=2;k<=m;k++){
		for(int j=k;j<=m;j++){
			for(int i=k;i<=n;i++){
				int mx=-0x3f3f3f;
				for(int c=1;c<=i;c++){
					if(a[c]&dp[i][j][k-1]>mx && dp[i][j][k-1]!=a[c]){
						mx=a[c]&dp[i][j][k-1];
					}
				}
				dp[i][j][k]=mx;
			}
		}
	}
	cout<<dp[n][m][m];
	return 0;
}
/*
5 3
31 3 1 15 7
*/


