#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
bitset<32> a[N],tmp[N],ans;
int cnt,num[32];
int n,m;

void t_sort(int p)
{
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i][p]) tmp[++cnt]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(!a[i][p]) tmp[++cnt]=a[i];
	}
	for(int i=1;i<=cnt;i++)
	{
		a[i]=tmp[i];
	}
}
/*
void check()
{
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<endl;
	}
}*/

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	scanf("%d%d",&n,&m);
	int x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[i]=x;
		for(int j=0;j<32;j++)
		{
			if(a[i][j]) num[j]++;
		}
	}
	int ed;
	for(int i=31;i>=0;i--)
	{
		if(num[i]>=m) {
			ed=i;
			break;
		}
	}
	for(int i=0;i<=ed;i++)
	{
		t_sort(i);
	}
	
	//check();//
	ans=a[1];
	for(int i=2;i<=m;i++)
	{
		ans &= a[i];
	}
	int t=0;
	for(int i=0;i<=31;i++)
	{
		t+=(bool(ans[i])<<i);
	}
	//cout<<ans<<endl;
	printf("%d",t);
	
	return 0;
}
