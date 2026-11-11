#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+7;
int dp[N],cnt[N];
int pos[N];
int L[N],R[N];
int n,d;
int c,T;
void init(){
	for(int l=1,r=1;r<=n;r++){
		while(pos[r]-pos[l]>d&&l<=r) l++;
		L[r]=l;
	}
	for(int l=n,r=n;l>=1;l--){
		while(pos[r]-pos[l]>d&&r>=l) r--;
		R[l]=r;
	}
//	for(int i=1;i<=n;i++) cout<<L[i]<<" ";cout<<"\n";
//	for(int i=1;i<=n;i++) cout<<R[i]<<" ";cout<<"\n";
//	cout<<"\n\n";
	return;
}
int solve1(){
	int res=0;
	for(int r=n;r>=1;r--){
		dp[r]=0,cnt[r]=1;
		for(int l=r-1;l>=1;l--){
			if(pos[r]-pos[l]<=d){
				dp[l]=1,cnt[l]=1;
				continue;
			}
			dp[l]=dp[R[l]]+1,cnt[l]=0;
			for(int k=R[l];k>=l;k--){
				if(dp[k]+1!=dp[l]) break;
				cnt[l]=cnt[l]+cnt[k];
				if(cnt[l]>2) break;
			}
			res=res+(cnt[l]==2);
		}
	}
	return res;
}
int solve2(){
	if(n<=10000) return solve1();
	int mid=0,res=0;
	for(int i=1;i<=n;i++){
		if(L[i]==1&&R[i]==n) mid=i;
	}
	for(int i=1;i<mid;i++){
		if(R[i]==mid) res=res+R[mid-1]-R[mid-2];
		if(R[i]-1==mid) res=res+R[mid]-R[mid-1];
	}
	return res;
}
int solve3(){
//	if(n<=10000) return solve1();
	for(int r=2;r<=n;r++){
		dp[r]=0;
		int l1,l2,l3;
		if(L[r]==r){
			dp[r]=dp[r]+dp[r-1];
			continue;
		}
		if(L[r]+1==r){
			l1=L[L[r]];
			l2=L[L[r]+1];
			dp[r]=dp[l2-1]-dp[l1-1];
		}else{
			l1=L[L[r]];
			l2=L[L[r]+1];
			l3=L[L[r]+2];
			dp[r]=(l3-l2)+dp[l2-1]-dp[l1-1];
		}
		dp[r]=dp[r]+dp[r-1];
	}
	return dp[n];
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>pos[i];
		init();
		int res;
		if(0<=c&&c<=10) res=solve1();
		else if(13<=c&&c<=14) res=solve2();
		else res=solve3();
		cout<<res<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
