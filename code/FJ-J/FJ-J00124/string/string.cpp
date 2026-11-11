#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,sum,midd,mi_id,cnt_1,cnt_2,ans;
int pre[N];
struct node
{
	int len;
	char x;
}a[N],b[N],c[N];
void init()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i].len>>a[i].x;
		pre[i]=pre[i-1]+a[i].len;
		sum+=a[i].len;
	}
	midd=sum/2;
	for(int i=1; i<=n; i++)
	{
		if(pre[i] >= midd)
		{
			mi_id=i;
			break;
		}
	}
	for(int i=1; i<=mi_id; i++)
	{
		if(i == mi_id)
		{
			if(midd == pre[i-1])
				continue;
			b[++cnt_1].x=a[i].x;
			b[cnt_1].len=midd-pre[i-1];
		}
		else
		{
			b[++cnt_1].x=a[i].x;
			b[cnt_1].len=a[i].len;
		}
	}	
	for(int i=n; i>=mi_id; i--)
	{
		if(i == mi_id)
		{
			if(midd == pre[i])
				continue;
			c[++cnt_2].x=a[i].x;
			c[cnt_2].len=pre[i]-midd;
		}
		else
		{
			c[++cnt_2].x=a[i].x;
			c[cnt_2].len=a[i].len;
		}
	}
}
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	init();
	int da_1=1,da_2=1,sh_1=b[1].len,sh_2=c[1].len;
	while(da_1 <= cnt_1 && da_2 <= cnt_2)
	{
		if(b[da_1].x != c[da_2].x)	
		{
			if(sh_1 >= sh_2)	
			{
				ans+=sh_2;
				sh_1-=sh_2;
				da_2++;
				sh_2=c[da_2].len;
			}
			else
			{
				ans+=sh_1;
				sh_2-=sh_1;
				da_1++;
				sh_1=c[da_1].len;
			}
		}
		else
		{
			if(sh_1 >= sh_2)	
			{
				sh_1-=sh_2;
				da_2++;
				sh_2=c[da_2].len;
			}
			else
			{
				sh_2-=sh_1;
				da_1++;
				sh_1=b[da_1].len;
			}
		}
	}
	cout<<ans;
	return 0;
}
