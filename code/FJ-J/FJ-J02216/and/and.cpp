#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
long long yv(long long a,long long b)
{
	long long aa[32],bb[32],cc[32],ah=31,bh=31,ch;
	for(int i=0;i<=31;i++)
	{
		aa[i]=0;
		bb[i]=0;
		cc[i]=0;
	}
	aa[31]=a;
	bb[31]=b;
	while(aa[ah]>1)
	{
		aa[ah-1]+=aa[ah]/2;
		aa[ah]=aa[ah]%2;
		ah--;
	}
	while(bb[bh]>1)
	{
		bb[bh-1]+=bb[bh]/2;
		bb[bh]=bb[bh]%2;
		bh--;
	}
	for(int i=1;i<=min(bh,ah);i++)
	{
		if(aa[i]==bb[i]&&aa[i]==1)
		{
			cc[i]=1;
			ch=i;
		}
	}
	while(ch!=1)
	{
		cc[ch-1]+=cc[ch]*2;
		ch--;
	}
	return cc[1]; 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	if(m==1)
	{
		ans=a[1];
	}
	if(m==2)
	{
		ans=0;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,yv(a[i],a[j]));
			}
	}
	if(m>=3)
	{
		ans=yv(a[1],a[2]);
		for(int i=3;i<=m;i++)
		{
			ans=yv(ans,a[i]);
		}
	}
	cout<<ans;
	return 0;
}
