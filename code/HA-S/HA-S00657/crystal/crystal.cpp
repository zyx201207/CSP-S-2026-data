#include <bits/stdc++.h>

using namespace std;

const int N=5e5+5;
typedef long long ll;

int n;
ll m,a[N];

int fro,bac,len,ans;
ll sumij;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ans=1;
	fro=1,bac=0,len=0;
	sumij=0;
	while(bac<n)
	{
		bac++;len++;
		sumij+=a[bac];
		if(a[bac]*len-sumij<=m)
		{
			ans=max(ans,len);
		}
		else
		{
			while(fro<=bac)
			{
				sumij-=a[fro];
				fro++;len--;
				if(a[bac]*len-sumij<=m)
				{
					ans=max(ans,len);
					break;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
