#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned ll
using VI=vector<int>;
using PI=pair<int,int>;
const int N=2e6+5;
ll n,d,a[N],x[N],s[N];
PI dp[N];int q[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;cin>>c>>T;while(T--){
		cin>>n>>d;ll ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++){
			x[i]=a[i+1]-a[i];
			s[i]=s[i-1]+x[i];
		}
		for(int r=1;r<=n;r++){
			for(int l=r-2;l>=1;l--){
				dp[l-1]={0,1};int head=1,tail=0;q[++tail]=l-1;
				for(int i=l;i<=r;i++){
					while(head<=tail&&s[i-1]-s[q[head]]>d)head++;
					dp[i]={dp[q[head]].first+1,dp[q[head]].second};
					for(int j=head+1;j<=tail;j++){
						if(dp[q[j]].first==dp[q[head]].first)dp[i].second+=dp[q[j]].second;
						else break;
					}
					while(head<=tail&&dp[i].first<dp[q[tail]].first)tail--;
					q[++tail]=i;
				}
//				cout<<l<<" "<<r<<" "<<dp[r].first<<" "<<dp[r].second<<"\n";
				if(dp[r].second==2){
//					cout<<l<<" "<<r<<"\n";
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
