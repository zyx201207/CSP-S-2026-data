#include<bits/stdc++.h>
using namespace std;
const int N=310;
long long a[N],dp[N],Cnt[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long C,T;
	cin>>C>>T;
	while(T--){
		long long n,d,cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int l=1;l<=n;l++){
			fill(dp+1,dp+n+1,1e9);
			fill(Cnt+1,Cnt+n+1,0);
			Cnt[l]=1;
			dp[l]=0;
			for(int r=l+1;r<=n;r++){
				long long minn=1e15;
				for(int k=r-1;k>=l;k--){
					if(a[k]+d<a[r]) break;
					minn=min(minn,dp[k]+1);
				}
				dp[r]=minn;
				if(minn>=1e15) break;
				for(int k=r-1;k>=l;k--){
					if(a[k]+d<a[r]) break;
					if(dp[k]+1==minn) Cnt[r]+=Cnt[k];
				}
				if(Cnt[r]==2) cnt++;
				else if(Cnt[r]>2) break;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
/*
0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
*/
