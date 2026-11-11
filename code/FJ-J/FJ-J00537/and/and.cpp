#include<bits/stdc++.h>
using namespace std;
int a[200010],maxn=0;
int a1[40],a2[40],a3[40];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
		maxn=max(maxn,a[i]);
	}
	if(m==1)cout<<maxn;
	else if(m==2)
	{
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				int o1=a[i],o2=a[j];
				int p1=0,p2=0;
				while(o1>0)
				{
					p1++;
					a1[p1]=o1%2;
					o1/=2;
				}
				while(o2>0)
				{
					p2++;
					a2[p2]=o2%2;
					o2/=2;
				}
				for(int k=max(p1,p2);k>0;k--)
				{
					if(a1[k]!=a2[k])a3[k]=0;
					else a3[k]=1;
				}
				int ow=1,s=0;
				for(int k=max(p1,p2);k>0;k--)
				{
					s+=ow*a3[k];
					ow*=2;
				}
				maxn=max(maxn,s);
			}
		cout<<maxn;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
