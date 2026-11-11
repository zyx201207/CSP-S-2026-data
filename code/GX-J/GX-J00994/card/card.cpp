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
ll n,m,a[5*100010],t[3*100010],ans[3*100010],tot,f[3*100010],flag[3*100010],l,r;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int k=1;k<=n;k++)
	{
		memset(f,0,sizeof(f));
		memset(t,0,sizeof(t));
		for(int i=k;i<=n;i++)
		{
			if(t[a[i]]==0) {tot++; f[tot]=a[i]; t[a[i]]=tot; ans[a[i]]++; continue;}
			else 
			{
				ll last=t[a[i]];
				for(int j=tot;j>last;j--)
					{t[f[j]]=0; ans[f[j]]--;} 
				tot=last;
			}
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
