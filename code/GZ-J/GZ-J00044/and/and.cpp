//GZ-J00044 贵州市花溪区实验中学 游梓一
#include<bits/stdc++.h>
using namespace std;
bool k[32],l[32];
int tt(int a,int b)
{
	return a>b;
}
int dd(int x,int y)
{
	int ks=0,ls=0;
	bool kd=0,ld=0;
	memset(k,0,sizeof(k));
	memset(l,0,sizeof(l));
	int i=pow(2,30),j=30;
	while(i!=0)
	{
		if(x>=i)
		{
			x-=i;
			k[j]=1;
			if(kd==0)
			{
				kd=1;
				ks=j;
			}
		}
		if(y>=i)
		{
			y-=i;
			l[j]=1;
			if(ld==0)
			{
				ld=1;
				ls=j;
			}
		}
		i/=2;
		j--;
	}
	int s=0;
	for(j=0,i=1;j<=(ks>ls?ks:ls);j++)
	{
		if(k[j]==l[j])s+=i;
		i*=2;
	}
	return s;
}
int a[200000],n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n,tt);
	for(int i=1;i<m;i++)
	{
		cout<<a[i-1]<<' '<<a[i]<<' ';
		a[i]=dd(a[i],a[i-1]);
		cout<<i<<' '<<a[i]<<endl;
	}
	printf("%d",a[m-1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
