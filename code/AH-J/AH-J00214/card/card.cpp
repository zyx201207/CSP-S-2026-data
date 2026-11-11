#include<bits/stdc++.h>
using namespace std;
int read()
{
	int f=1,sum=0;
	char ch=getchar_unlocked();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar_unlocked();
	}
	while(ch>='0'&&ch<='9') 
	{
		sum=sum*10+ch-'0';
		ch=getchar_unlocked();
	}
	return f*sum;
}
void write(int x)
{
	if(x<0)
	{
		putchar_unlocked('-');
		x=-x;
	}
	if(x==0)
	{
		putchar_unlocked('0');
		return ;
	}
	char c[20];
	int sum=0;
	while(x!=0)
	{
		c[++sum]=x%10+'0';
		x/=10;
	}
	for(int i=sum;i>=1;i--) putchar_unlocked(c[i]);
}
int a[200010];
int b[200010];
int c[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
	{
		stack<int>q;
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==0)
			{
				q.push(a[j]);
				b[a[j]]=1;
			}
			else {
				while(q.size()>0)
				{
					int x=q.top();
					if(x==a[j]) break;
					b[x]=0;
					q.pop();
				}
			}
		}
		while(q.size()>0)
		{
			int x=q.top();
			c[x]++;
			q.pop();
		}
		for(int j=1;j<=n;j++) b[j]=0;
	}
	for(int i=1;i<=m;i++) {write(c[i]);printf(" ");}
	return 0;
}
