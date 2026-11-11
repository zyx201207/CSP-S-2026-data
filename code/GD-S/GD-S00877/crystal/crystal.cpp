#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[200010];
long long s[200010];
long long dp[20010][1000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i=2;i<=n;i++){
		s[i]=a[i]-a[i-1];
		if(s[i]==0)ans++;
	}
	for(int i=2;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[i][j]=dp[i][j-1]+s[j];
		}
	}
//	for(int i=2;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	int asss=0;
	for(int i=2;i<=n;i++){
		int axx=0;
		for(int j=i;j<=n;j++){
			m-=dp[i][j];
			axx++;
			if(m<0)break;
		}
		asss=max(axx,asss);
	}
	cout<<asss;
	
	
	return 0;
}
