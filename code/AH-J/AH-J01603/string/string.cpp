#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct cyb 
{
	int a;
	char c;
}b[200005];
cyb hhc[200005],zxq[200005]; //Ä¤°Ý´óÀÐ 
int tp1,cp1,tp2,cp2;
bool f;
int ans;

long long jh()
{
	long long sm=0;
	for(int i=1;i<=n;++i)
	{
		sm+=((b[i].a));
	}
	return sm;
}

void jcl()
{
	long long x,m;
	cyb q,h;
	x=jh();
	//cout<<x<<"\n";
	m=x/2+1;
	int cnt=0;
	while(m-b[++cnt].a>0)
	{
		m-=b[cnt].a;
		//cout<<m<<" 2\n";
	}
	q.a=m-1;q.c=b[cnt].c;
	h.a=b[cnt].a-m;h.c=b[cnt].c;
	for(int i=cnt-1;i>0;--i)
	{
		hhc[++tp1].a=b[i].a;
		hhc[tp1].c=b[i].c;
	}
	hhc[++tp1].a=q.a;
	hhc[tp1].c=q.c;
	zxq[++tp2].a=h.a;
	zxq[tp2].c=h.c;
	for(int i=cnt+1;i<=n;++i)
	{
		zxq[++tp2].a=b[i].a;
		zxq[tp2].c=b[i].c;
	}
	//cout<<cnt<<" 1\n";
	return ;
}

void ocl()
{
	long long x,m;
	cyb q,h;
	x=jh();
	m=x/2;
	int cnt=0;
	while(m-b[++cnt].a>=0)
	{
		m-=b[cnt].a;
	}
	q.a=m;q.c=b[cnt].c;
	h.a=b[cnt].a-m;h.c=b[cnt].c;
	for(int i=cnt-1;i>0;--i)
	{
		hhc[++tp1].a=b[i].a;
		hhc[tp1].c=b[i].c;
	}
	hhc[++tp1].a=q.a;
	hhc[tp1].c=q.c;
	zxq[++tp2].a=h.a;
	zxq[tp2].c=h.c;
	for(int i=cnt+1;i<=n;++i)
	{
		zxq[++tp2].a=b[i].a;
		zxq[tp2].c=b[i].c;
	}
	return ;
}

void sv ()
{
	int hc,xq;
	char h_c,x_q;
	hc=hhc[++cp1].a;
	xq=zxq[++cp2].a;
	h_c=hhc[++cp1].c;
	x_q=zxq[++cp2].c;
	while((!(cp1>tp1))&&(!(cp2>tp2)))
	{
		if(hc<xq) 
		{
			if(h_c!=x_q)
			{
				ans+=hc;
			}
			xq-=hc;
			hc=hhc[++cp1].a;
			h_c=hhc[++cp1].c;
		}
		else if(hc>xq) 
		{
			if(h_c!=x_q)
			{
				ans+=xq;
			}
			hc-=xq;
			xq=zxq[++cp2].a;
			x_q=zxq[++cp2].c;
		}
		else if(hc=xq) 
		{
			if(h_c!=x_q)
			{
				ans+=hc;
			}
			hc=hhc[++cp1].a;
			xq=zxq[++cp2].a;
			h_c=hhc[++cp1].c;
			x_q=zxq[++cp2].c;
		}
	}
	ans+=hc+xq;
}

signed main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>b[i].a>>b[i].c;
		if(b[i].a%2)
		{
			f=!f;
		}
	}
	if(f)
	{
		jcl();
	}
	else 
	{
		ocl();
	}
//	for(int i=1;i<=tp1;++i)
//	{
//		cout<<hhc[i].a<<" "<<hhc[i].c<<"\n";
//	}
//	for(int i=1;i<=tp2;++i)
//	{
//		cout<<zxq[i].a<<" "<<zxq[i].c<<"\n";
//	}
	sv();
	cout<<ans;
	return 0;
}
