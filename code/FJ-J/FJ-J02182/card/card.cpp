#include<bits/stdc++.h>
using namespace std;
int n,m,a[30010],z[30010],ans[30010],zz=1,can,i1=2;
void cz(int x)
  {for(int j=1;j<zz;j++)
	if(z[j]==a[x])
	  {can=j;
	  return ;}
  return ;}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(ans,0,sizeof(a));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  {cin>>a[i];
	  can=0;
	  cz(i);
	  if(can==0)z[zz]=a[i];
	  else zz=can;
	  zz++;}
	for(int i=1;i<zz;i++)
	  ans[z[i]]++;
	for(int i=2;i<=n;i++)
	  {zz=1;
	  for(int j=i;j<=n;j++)
		{can=0;
		cz(j);
		if(can==0)z[zz]=a[j];
		else zz=can;
		zz++;}
	  for(int j=1;j<zz;j++)
		ans[z[i]]++;}
	for(int i=1;i<=m;i++)
	  cout<<ans[i]<<" ";
	return 0;
}