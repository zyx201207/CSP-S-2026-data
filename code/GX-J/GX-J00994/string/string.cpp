#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
#define ll long long
char c[2*100010];
ll f[2*100010],ans,l,r,n,tot;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		{
		tot++;	
		cin>>f[tot]>>c[tot];
		if(c[tot]==c[tot-1]) {f[tot-1]+=f[tot]; tot--;}}
	l=1,r=tot;
	while(tot>1)
	{
		ll q=min(f[l],f[r]);
		if(c[l]==c[r])
		{
			f[l]-=q; if(f[l]==0) {l++; tot--;}
			f[r]-=q; if(f[r]==0) {r--; tot--;}
		 }
		 else
		 {
			ans+=q;
			f[l]-=q; if(f[l]==0) {l++; tot--;}
			f[r]-=q; if(f[r]==0) {r--; tot--;}
		}
	}
	cout<<ans;
	return 0;
}
