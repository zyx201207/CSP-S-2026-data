#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=2e6+1;
int c,t,n,d;
int x[N];

void solve40(){
	int ans=0;
	cin>>n>>d;
	int dp[n+1][n+1],minn[n+1][n+1];
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int len=1;len<n;len++){
		for(int i=1;i+len<=n;i++){
			int j=i+len;
			dp[i][j]=0,minn[i][j]=N;
			if(x[j]-x[i]<=d){
				dp[i][j]=1,minn[i][j]=0;
				continue;
			}
			for(int k=i+1;k<j;k++){
				if(minn[i][k]<N&&minn[k][j]<N&&minn[i][j]>=minn[i][k]+1+minn[k][j]){
					if(minn[i][j]==minn[i][k]+1+minn[k][j]) dp[i][j]+=dp[i][k]*dp[k][j];
					else dp[i][j]=dp[i][k]*dp[k][j];
					minn[i][j]=minn[i][k]+1+minn[k][j];
				}
			}
			if(dp[i][j]==2) ans++;
		}
	}
	cout<<ans<<"\n";
	return;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>t;
	if(c<=10){
		while(t--){
			solve40();
		}
	}
	if(c==11||c==12){
		while(t--){
		    cin>>n>>d;
		    for(int i=1;i<=n;i++) cin>>x[i];
		    if(2*(x[2]-x[1])>d) cout<<0<<"\n";
		    else cout<<n-2*d/(x[2]-x[1])+1<<"\n";
	    }
	}
	return 0;
}

/*
in:
0 3
4 2
1 2 3 4
5 2
1 2 3 4 5
6 2
1 2 3 4 5 6
6 3
1 2 3 4 5 6
6 7
3 6 9 12 15 18
6 3
1 2 5 6 8 9

out:
1
2
3

*/