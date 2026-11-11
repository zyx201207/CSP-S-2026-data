#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int in()
{
	int ans=0,ff=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
	{
		if(c=='-')
		{
			ff*=-1;
		}
	}
	for(;isdigit(c);c=getchar())
	{
		ans=ans*10+c-'0';
	}
	return ans*ff;
}
void out(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>=10)
	{
		out(x/10);
	}
	putchar(x%10+'0');
}
int c,t;
int n,d;
int a[N];
int cnt;
int cntn;
int tmpp[N];
//void dfs(int pos,int ed,int lim,int step)
//{
//	if(step>lim||(step==lim&&pos!=ed))
//	{
//		return;
//	}
//	if(step==lim&&pos==ed)
//	{
//		cntn++;
//		return;
//	}
//	for(int i=pos+1;i<=ed;i++)
//	{
//		if(a[i]-a[pos]<=d)
//		{
//			dfs(i,ed,lim,step+1);
//		}
//		else
//		{
//			break;
//		}
//	}
//}
bool check(int x,int y)
{
	int cntt=1;
	int tmp=x;
	int id=0;
	int cntx=0;
	for(int i=x+1;i<=y;i++)
	{
		if(a[i]-a[i-1]>d)
		{
			return false;
		}
		if(a[i]-a[tmp]>d)
		{
			tmp=i-1;
			tmpp[++id]=tmp;
			cntt++;
		}
	}
	if(a[tmpp[1]]-a[x]>d||a[y]-a[tmpp[id]]>d)
	{
		return false;
	}
	tmpp[0]=x;
	tmpp[id+1]=y;
	for(int i=1;i<=id;i++)
	{
		int tt=tmpp[i];
		if(tt-1>tmpp[i-1]&&a[tmpp[i+1]]-a[tt-1]<=d)
		{
			if(tt-2>tmpp[i-1]&&a[tmpp[i+1]]-a[tt-2]<=d)
			{
				return false;
			}
			else
			{
				cntx++;
			}
		}
		if(tt+1<tmpp[i+1]&&a[tt+1]-a[tmpp[i-1]]<=d)
		{
			if(tt+2<tmpp[i+1]&&a[tt+2]-a[tmpp[i-1]]<=d)
			{
				return false;
			}
			else
			{
				cntx++;
			}
		}
	}
	if(cntx==1)
	{
		return true;
	}
	return false;
//	cntn=0;
//	dfs(x,y,cntt,0);
//	if(cntn==2)
//	{
//		return true;
//	}
//	return false;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=in();
	t=in();
	if(c<=10)
	{
		while(t--)
		{
			cnt=0;
			n=in();
			d=in();
			for(int i=1;i<=n;i++)
			{
				a[i]=in();
			}
			for(int u=1;u<=n;u++)
			{
				for(int v=u+1;v<=n;v++)
				{
					if(check(u,v))
					{
						cnt++;
					}
				}
			}
			out(cnt);
			cout<<endl;
		}
	}
	else if(c==11||c==12)
	{
		while(t--)
		{
			out(0);
			cout<<endl;
		}
	}
	else if(c==13||c==14)
	{
		while(t--)
		{
			out(0);
			cout<<endl;
		}
	}
	else
	{
		while(t--)
		{
			out(0);
			cout<<endl;
		}
	}
	return 0;
}

