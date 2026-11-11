#include<bits/stdc++.h>
using namespace std;
long long n,m,mm,a[200010],f[200010][40],d[40],ans;
bool v[200010];
bool cmp(long long a,long long b)
{
	return a>b;
}
void mj(int x)
{
	int pp=a[x],k=1,s=0;
	while(pp>k)
	{
		if(pp<k*2)break;
		k*=2;
		s++;
	}
	while(pp>0&&s>=0&&k>0)
	{
		if(pp>=k)
		{
			f[x][s]=1;
			pp-=k;
		}
		k/=2;
		s--;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	mm=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		mj(i);
	} 
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=30;j++)
		{
			d[j]+=f[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=30;j>=0;j--)
		{
			if(d[j]>=m&&f[i][j]==1&&mm>0)
			{
				if(ans==0)ans=a[i];
				else ans&=a[i];
				mm--;
				v[i]=true;
				break;
			}
		}
	}
	if(mm)
	{
		for(int i=n;i>=1;i--)
		{
			if(v[i])continue;
			if(mm==0)continue;
			ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
} 
