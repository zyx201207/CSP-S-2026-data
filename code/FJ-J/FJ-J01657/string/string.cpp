#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int n,cnt;
ll s,dp[5005][5005];
string v;
struct p{
	ll a;
	char c;
}x[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(int i=1;i<=n;i++){
		ll u;
		char v;
		cin>>u>>v;
		if(v!=x[cnt].c){
			x[++cnt].a=u;
			x[cnt].c=v;
		}else{
			x[cnt].a+=u;
		}
	}
	s=x[1].a;
	for(int i=2;i<=cnt;i++){
		s=__gcd(s,x[i].a);
	}
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=x[i].a/s;j++){
			v+=x[i].c;
		}
	}
	for(int i=1;i<=v.size()/2;i++){
		for(int j=v.size()-v.size()/2+1;j<=v.size();j++){
			if(v[i-1]==v[j-1]){
				dp[i][j]=dp[i+1][j-1];
			}else{
				dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
			}
		}
	}
	cout<<dp[1][v.size()]*s;
	return 0;
}
