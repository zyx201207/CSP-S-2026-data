#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,t;
//struct xxs
//{
//	int num,v;
//}f[200005];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
//	f[1].num=a[1];
//	if(a[1]!=0)	f[1].v=1;
//	for(int i=2;i<=n;i++)
//		if(f[i-1].v<m)	
//			f[i].num=max(f[i-1].num&a[i],f[i-1].num),f[i].v++;
//		if(gg_and(f[i-1],a[i])>f[i-1].num&&f[i-1].v<m)
//			f[i].num=gg_and(f[i-1],a[i]),f[i].v=f[i-1].v;
//		else	f[i].num=f[i-1].num,f[i].v=f[i-1].v;
//	for(int i=1;i<=n;i++)	cout<<a[i]<<' ';
//	cout<<endl;
	ans=a[1],t=1;
	for(int i=2;i<=m;i++)
	{
		
		if((ans&a[i])==0&&m+t<=n)
		{
			ans=a[i];
			m+=t,t=0;
			continue;
		}
		ans=ans&a[i];
		t++;
	}
	cout<<ans;
	
	return 0;
}
