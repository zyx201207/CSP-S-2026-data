#include<bits/stdc++.h>
using namespace std;
long long n,m,x,a[200005][32],w,sum,ans;
bool ok[200005];
int main()
{
	cin.tie(0),ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>x,w=0,ok[i]=1;
		while(x) a[i][w]=x&1,x>>=1,w++;
	}
	for(long long ew=31;ew>=0;ew--)
	{
		sum=0;
		for(long long i=0;i<n;i++) sum+=a[i][ew]*ok[i];
		if(sum>=m)
		{
			ans+=(1<<ew);
			for(long long i=0;i<n;i++) if(!a[i][ew]) ok[i]=0;
		}
	}
	cout<<ans;
	return 0;
}
/*
0011
1111
1100
1100

11111
01111
00111
00011
00001 
*/
