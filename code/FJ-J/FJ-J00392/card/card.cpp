#include<iostream>
#include<stack>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int lst[N];
bool tsa=true;
stack<int> st;
bool inst[N];
int ans[N];
int na[N],tot;
int cnt[N];
inline int read(){char cc=getchar();int z=0,fh=1;while((cc<'0' || cc>'9') && cc!='-'){cc=getchar();}if(cc=='-'){fh=-1;cc=getchar();}while(cc>='0' && cc<='9'){z=z*10+cc-'0';cc=getchar();}return z*fh;}
inline void write(int x){if(x==0){putchar('0');return ;}if(x<0){putchar('-');x=-x;}int z[20],tt=0;while(x){z[++tt]=x%10;x/=10;}for(int i=tt;i;i--){putchar(z[i]+'0');}}
inline void cl(int s,int a[],int n)
{
	while(!st.empty()) st.pop();
	for(int i=1;i<=m;i++)
	{
		inst[i]=false;
	}
	for(int i=s;i<=n;i++)
	{
		if(inst[a[i]])
		{
			int tp=st.top();
			while(tp!=a[i])
			{
				inst[tp]=false;
				st.pop();
				tp=st.top();
			}
		}
		else
		{
			st.push(a[i]);
			inst[a[i]]=true;
		}
	}
	while(!st.empty())
	{
		int tp=st.top();
		st.pop();
		ans[tp]+=cnt[s];
	}
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		lst[a[i]]=i;
		if(i>1 && a[i-1]>a[i]) tsa=false;
		cnt[i]=1;
	}
	if(tsa)
	{
		for(int i=1;i<=m;i++)
		{
			write(lst[i]);
			putchar(' ');
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==1 || a[i]!=a[i-1])
		{
			na[++tot]=a[i];
			cnt[tot]=1;
		}
		else
		{
			++cnt[tot];
		}
	}
	for(int i=1;i<=tot;i++)
	{
		cl(i,na,tot);
	}
	for(int i=1;i<=m;i++)
	{
		write(ans[i]);
		putchar(' ');
	}
	
	return 0;
}
/*
4 3
1 2 1 3

3 1 4

10 3
3 1 2 1 3 2 3 1 2 1

10 3 3
*/
/*
can AC:
1~12
15~17
20

sum:15*4=60pts

writeing:
13,14
*/
