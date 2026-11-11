#include <bits/stdc++.h>
using namespace std;
long long n,m,f[500005],nex[500005],maxx=-1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin >>f[i];//不知道有啥用写了再说。 
	}
	for (int i=1;i<=n;i++)
	{
		if(i!=n)
		{
			if(f[i]-f[i+1]>=0)nex[i]=f[i]-f[i+1];
			else nex[i]=f[i+1]-f[i];
		}
	}
	for (int i=1;i<=n;i++)
	{
		long long k=m,now=i,ans=1;//耶，暴力 
		while(now<n)//把你当开头，耶 
		{
			if(k-nex[now]>=0){
			
				k-=nex[now]*ans;
				now++;
				ans++;
			}
			else break;
		}
		maxx=max(maxx,ans);
	}
	cout <<maxx;
	return 0;
	
 } 



