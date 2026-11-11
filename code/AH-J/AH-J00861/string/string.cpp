#include<bits/stdc++.h>
using namespace std;
using LL=long long;

const int N=6e5+10;

struct Node {
	LL len;
	int c;//length,char
}a[N],b[N],c[N];//in,left,right
int bu,cu;//num_b,num_c

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n; scanf("%d",&n);
	LL num;char ch;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld %c",&num,&ch);
		a[i]={num,int(ch)};
	}
	
	int l=1,r=n;
	while(l<r)
	{
		if(a[l].len<a[r].len)
		{
			b[++bu]={a[l].len,a[l].c};
			c[++cu]={a[l].len,a[r].c};
			a[r].len-=a[l].len;
			l++;
		}
		else if(a[l].len>a[r].len)
		{
			b[++bu]={a[r].len,a[l].c};
			c[++cu]={a[r].len,a[r].c};
			a[l].len-=a[r].len;
			r--;
		}
		else
		{
			b[++bu]={a[r].len,a[l].c};
			c[++cu]={a[r].len,a[r].c};
			l++,r--;
		}
	}
	
	//check();//
	
	LL ans=0;
	for(int i=1;i<=bu;i++)
	{
		if(b[i].c!=c[i].c)
			ans+=b[i].len;
	}
	printf("%lld",ans);
	
	return 0;
}
