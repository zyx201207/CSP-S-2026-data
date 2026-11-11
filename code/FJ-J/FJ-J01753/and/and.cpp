#include<bits/stdc++.h>
using namespace std;
int n,m,s[200005],dp[200005],ans,cnt;
bool cmp(int x,int y){
	int bx=__builtin_popcount(x);
	int by=__builtin_popcount(y);
	if(bx!=by) return __builtin_popcount(x)>__builtin_popcount(y); 
	else return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0),cout.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>s[i];
sort(s+1,s+n+1,cmp);
ans=s[1];
for(int i=1;i<=m;i++)ans&=s[i];

cout<<ans;
	return 0;
}
