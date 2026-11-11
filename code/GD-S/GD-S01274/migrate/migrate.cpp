#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int a[305];
int nex[305];
int dp[305][305];
int cnt[305][305];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}int l=1,r=1;
		for(l=1;l<=n;l++){
			while(r<n && a[r+1]-a[l]<=d)r++;
			nex[l]=r;
		}int cnti=0;
		for(int i=1;i<=n;i++){
			int l=i,r=i;
			dp[i][i]=0;
			cnt[i][i]=1;
			while(r+1<=nex[r]){
				for(int j=r+1;j<=nex[r];j++){
					cnt[i][j]=0;
					for(int p=r;p>=l;p--){
						if(nex[p]<j)break;
						cnt[i][j]+=cnt[i][p];
						dp[i][j]=dp[i][p]+1;
					}if(cnt[i][j]==2){
						cnti++;
					}
				}l=r+1;
				r=nex[r];
			}
		}cout<<cnti<<"\n";
	}
	return 0;
} 
