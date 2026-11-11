#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans,c,dp[25][5000];
bool flag;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	if(n==1){
		cout<<1;
		return 0;
	}
	cin>>a[2];
	c=a[2]-a[1];
	if(n==2){
		if(c<=m)	cout<<2;
		else	cout<<1;
		return 0;
	}
	
	for(int i=3;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=c)
			flag=1;
	}
	sort(a+1,a+1+n);
	
	if(!flag){
		bool k=0;
		long long x=m/c;
		for(int i=1;i<=n;i++){
			m-=i*c;
			if(m<0)	break;
			ans++;
			if(i==n)	k=1;
		}
		cout<<k<<endl;
		if(!k)	cout<<ans+1;
		else	cout<<ans;
		return 0;
	}else{
		for(int i=0;i<=m;i++)	dp[1][i]=1;
		for(int i=0;i<=n;i++)	dp[i][0]=1;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=m;j++){
				int x=(i-1)*(a[i]-a[i-1]);
				if(x>j)	dp[i][j]=dp[i-1][j];
				else	dp[i][j]=max(dp[i-1][j],dp[i-1][j-x]+1);
			}
		}
		cout<<dp[n][m];
	}
	return 0;
}
