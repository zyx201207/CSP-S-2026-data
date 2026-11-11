#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,k[N],l,maxn,s[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>k[i-1];
	sort(k,k+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+k[i-1];
	l=1;
	for(int i=1;i<=n;i++)
	{
		while(k[i-1]*(i-l+1)-s[i]+s[l-1]>m) l++;
		maxn=max(maxn,i-l+1);
	}
	cout<<maxn<<endl;
	return 0;
}
