#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],dp[N];
int n,m;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; ++i) {
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	for(int i=1; i<=n; ++i) {
		for(int j=m; j>=0; --j) {
			if(j>=1) {
				auto d=dp[j-1]&a[i];
//				cout<<dp[j-1]<<' '<<a[i]<<' '<<d<<endl;
				if(dp[j-1]==0) {
					dp[j]=max(a[i],dp[j]);
				} else {
					dp[j]=max(dp[j-1]&a[i],dp[j]);
				}
			}
//			for(int i=1;i<=m;++i){
//				cout<<dp[i]<<' ';
//			}
//			cout<<endl;
		}
	}
	cout<<dp[m];
	return 0;
}
/*
   3 15 12 12
   0 1 2
dp 0 3 3

我竟然写出来了！？
2026.10.31 11:12
你是内内个内内内个内个内内
  内内个内内内个内个内内 
     阳光彩虹小白马
    滴滴打滴滴答~~~ 
	
	
	
	
香火在雨中燒幾十個暑和寒
血脈相連一脈苦行山

 
*/
