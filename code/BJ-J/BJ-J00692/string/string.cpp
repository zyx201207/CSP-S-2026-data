#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int num[N];
char c[N];
int n;
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>num[i]>>c[i];
	int l=1,lnum=num[1],lc=c[1];
	int r=n,rnum=num[n],rc=c[n];
	while(1)
	{
		if(lc==rc)
		{
			if(lnum>rnum)
			{
				lnum-=rnum;
				rnum=num[--r];
				rc=c[r];
			}
			else if(lnum<rnum)
			{
				rnum-=lnum;
				lnum=num[++l];
				lc=c[l];
			}
			else
			{
				lnum=num[++l];
				lc=c[l];
				rnum=num[--r];
				rc=c[r];
			}
		}
		else
		{
			if(lnum>rnum)
			{
				ans+=rnum;
				lnum-=rnum;
				rnum=num[--r];
				rc=c[r];
			}
			else if(lnum<rnum)
			{
				ans+=lnum;
				rnum-=lnum;
				lnum=num[++l];
				lc=c[l];
			}
			else
			{
				ans+=lnum;
				lnum=num[++l];
				lc=c[l];
				rnum=num[--r];
				rc=c[r];
			}
		}
		if(l>=r) break;
	}
	cout<<ans;
	return 0;
}
