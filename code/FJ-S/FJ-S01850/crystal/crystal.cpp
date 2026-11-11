#include<bits/stdc++.h>
using namespace std;
#define int long long
#define file(S) freopen(S".in","r",stdin),freopen(S".out","w",stdout);
const int N=5e5+10;
int v[N],sum[N],n,m;
bool check(int p,int x)
{
	if(x>p) return 0; 
	return ((x-1)*v[p]-(sum[p-1]-sum[p-x]))<=m; 
}
void Luo_Saisei() {//注意到是单增 找一个最大的就好 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
	sort(v+1,v+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+v[i];
	int Ans=1;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=1e18,ans=-1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(i,mid)) ans=mid,l=mid+1;
			else r=mid-1;
		}
		Ans=max(Ans,ans);
	}
	cout<<Ans<<'\n';
	return ;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	file("crystal");
	int T=1;
//	cin>>T;
	while(T--) Luo_Saisei();
}
//15min
