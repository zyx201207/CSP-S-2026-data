#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+50;
ll n,m,a[N],p[N];
ll maxn=-1,x,t;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++)
	{	
		for(ll k=i+1;k<=n-m+2;k++)
		{
			if(m==1)
			{
				maxn=a[i];
				break;
			}
			else if(m==2)
			{
				maxn=a[i]&a[k];
				break;
			}
			t=m;
			x=k+1;
			p[i]=a[i]&a[k];
			while(t-2>0)
			{
				p[i]=p[i]&a[x++];
		 		t--;
		 		if(p[i]>maxn)
				{
		 			maxn=p[i];
				}
			}
		}
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;

}
