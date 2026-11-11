#include<bits/stdc++.h>
using namespace std;
const int N=1e8+10;
int st=1,ed,n,ids=1,idd,ans,len,x;
char a[N],y;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		for(int j=1;j<=x;j++)
		{
			a[++len]=y;
		}
	}
	for(int i=1;i<=len/2;i++)if(a[i]!=a[len-i+1])ans++;
	cout<<ans;
   return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
