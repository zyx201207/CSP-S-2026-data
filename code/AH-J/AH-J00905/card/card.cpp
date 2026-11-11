#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005],a1[300005];
int main(){
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
if(m==1)
{
	cout<<n;
	return 0;
}
for(int i=1;i<=n;i++)
{
	memset(c,0,sizeof(c));
	for(int j=1;j<=n;j++) b[j]=a[j];
	long long n1=0;
	for(int j=i+1;j<=n;j++)
	{
		bool f=1;
		for(int k=1;k<=n1;k++)
		{
			if(b[j]==c[k])
			{
				f=0;
				n1=k;
				break;
			}
		}
		if(f) c[++n1]=b[j];
	}
	for(int j=1;j<=n1;j++) a1[c[j]]++;
}
for(int i=1;i<=m;i++)
{
	cout<<a1[a[i]]<<" ";
}
	return 0;
	}
