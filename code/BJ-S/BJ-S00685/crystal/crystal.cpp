#include <bits/stdc++.h>
using namespace std;

const int MAXN=5010;
int n;
long long m,a[500010];
long long dp[MAXN][MAXN];
bool f[MAXN][MAXN];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool all=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(all==1){
			if(a[i]!=i){
				all=0;
			}
		}
	}
	if(all==1){
		long long num=0;
		for(int i=1;i<=n-1;i++){
			num+=i;
			if(num>m){
				cout<<i<<endl;
				return 0;
			}
		}
		cout<<n<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
		f[i][i]=1;
	}
	for(int len=1;len<n;len++){
		bool flag=0;
		for(int i=1;i+len<=n;i++){
			int j=i+len;
			int mid=(i+j)>>1;
			if(f[i][mid]==0||f[mid+1][j]==0){
				continue;
			}
			dp[i][j]=dp[i][mid]+dp[mid+1][j]+(mid-i+1)*(a[j]-a[mid]);
			if(dp[i][j]<=m){
				f[i][j]=1;
				flag=1;
			}
		}
		if(flag==0){
			cout<<len<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
	return 0;
}
//dp[i][j]=1-i all change to j
//dp[i][j]=dp[i][j-1]+i

//dp[i][j] i-j combine = dp[i][k]+dp[k+1][j]+size[i][k]*(max[k+1][j]-max[i][k])
