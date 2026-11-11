#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
LL s[100000010];
LL ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(LL i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	sort(s+n,s+n+1);
	int mid=s[(n+1)/2];
	for(LL i=1;i<=mid;i++)
	{
	 while(s[i]!=mid&&m>0)
	  {	
			s[i]+=1;
		    m--; 
	  }
	}
	for(int i=1;i<=n;i++)
	{
	  if(s[i]==mid) ans++;
	}
	cout<<ans;
	return 0;
 } 
