#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m;
int maxp,ans;
int a[N],cnt[35];
inline void solve(){
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++){
		int p=0,A=a[i];
		while(A){
			cnt[++p]+=A&1;
			A>>=1;
		}
		maxp=max(maxp,p+1);
	}
	for(int i=maxp;i>=1;i--){
		if(cnt[i]>=m){
			int num=pow(2,i-1),tot=0;
			for(int j=1;j<=n;j++)
				if(a[j]&num)
					a[++tot]=a[j]%num;
			ans+=num,n=tot;
			solve();
			return;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;//3500000 3e6
	for(int i=1;i<=n;i++)
		cin>>a[i];
	solve();
	cout<<ans<<'\n';
	return 0;
}
/*
4 2
1000 0111 0101 0001

4 2
8 7 5 1

5 2
1000 1001 1100 0110 0101

5 3
31 3 1 15 7
11111 11 1 1111 111
*/
