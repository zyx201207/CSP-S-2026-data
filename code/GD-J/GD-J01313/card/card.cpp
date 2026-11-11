#include<bits/stdc++.h>
using namespace std;
int a[500005],t[500005],s[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,len=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			len++;
			t[len]=a[j];
			for(int k=1;k<len;k++)
			if(t[k]==t[len])
			{
				for(int y=k;y<len;y++) t[y]=0;
				break;
			}
		}
		for(int k=1;k<=len;k++)
		{
			s[t[k]]++;
		}
		memset(t,0,len);
		len=0;
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
	return 0;
}
