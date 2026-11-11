#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e5+5;
char c[N];
int n,cnt,a[N],f[N][26];
inline int solve(int l,int r,char cc)
{
	int rr=lower_bound(a+1,a+n+1,cnt-l+1)-a,rl=lower_bound(a+1,a+n+1,cnt-r+1)-a;
	if(rl==rr) return r-l+1-(c[rr]==cc)*(r-l+1);
	return r-l+1-(max(0ll,f[rr-1][cc-'a']-f[rl][cc-'a'])+(a[rl]-(cnt-r+1)+1)*(c[rl]==cc)+(cnt-l+1-a[rr-1])*(c[rr]==cc));
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	cin>>a[i]>>c[i],cnt+=a[i],a[i]+=a[i-1];
	for(int i=1;i<=n;++i)
	{
		f[i][c[i]-'a']=f[i-1][c[i]-'a']+a[i]-a[i-1];
		for(int j=0;j<26;++j)
		if(j!=(c[i]-'a')) 
		f[i][j]=f[i-1][j];
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int l=a[i-1]+1,r=a[i];
		if(r>cnt/2) r=cnt/2;
		ans+=solve(l,r,c[i]); 
		if(a[i]>=cnt/2) break;
	}
	cout<<ans;
	return 0;
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
//aaaaa
