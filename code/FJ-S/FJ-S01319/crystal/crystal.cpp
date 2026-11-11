#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long res=0,fh=1;
	char ch;
	ch=getchar();
	while(ch<'0' or ch>'9')
	{
		if(ch=='-')fh=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9')
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*fh;
}
void printtttt(long long x)
{
	if(x>=10)printtttt(x/10);
	putchar(x%10+'0');
	return ;
}
void write(long long x,bool hh)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	printtttt(x);
	if(hh)putchar('\n');
	else putchar(' ');
	return ;
}
const long long maxn=999999999999999;
long long n,m,l,r,ll,rr,minnczc,minipczc,czc,cnt,ans,mm;
long long a[5000005];
vector<long long>v;
long long check(long long x)
{
	mm=m;
	l=x;
	r=x+1;
	if(l==1)ll=maxn;
	else ll=a[l]-a[l-1];
	if(r==n)rr=maxn;
	else rr=(a[r+1]-a[r])*2;
	czc=a[r];
	//write(m,false);
	//write(rr,true);
	mm-=minnczc;
	while(l>=1 and r<=n)
	{
		/*if(l==1 and r==n)
		{
			write(n,true);
			return 0;
		}*/
		if(mm<ll and mm<rr)break;
		if(ll==maxn)
		{
			if(rr<=mm)
			{
				mm-=rr;
				r++;
				cnt++;
				if(r==n)rr=maxn;
				else rr=(a[r+1]-a[r])*cnt;
			}
			else
			{
				break;
			}
		}
		else if(rr==maxn)
		{
			if(ll<=mm)
			{
				mm-=ll;
				l--;
				cnt++;
				if(l==1)ll=maxn;
				else ll=a[r]-a[l-1];
			}
			else
			{
				break;
			}
		}
		else if(ll<=rr)
		{
			if(ll<=mm)
			{
				mm-=ll;
				l--;
				cnt++;
				if(l==1)ll=maxn;
				else ll=a[r]-a[l-1];
			}
		}
		else
		{
			if(rr<=mm)
			{
				mm-=rr;
				r++;
				cnt++;
				if(r==n)rr=maxn;
				else rr=(a[r+1]-a[r])*cnt;
			}
		}
		//write(m,false);
		//write(ll,false);
		//write(rr,true);
		/*write(m,false);
		write(a[l],false);
		write(l,false);
		write(a[r],false);
		write(r,true);
		*/
	}
	return r-l+1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(long long i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	minnczc=maxn;
	for(long long i=1;i<n;i++)
	{
		if(a[i+1]-a[i]<minnczc)
		{
			minnczc=a[i+1]-a[i];
			v.clear();
			v.push_back(i);
		}
		else if(a[i+1]-a[i]==minnczc)
		{
			v.push_back(i);
		}
	}
	if(m<minnczc)
	{
		write(1,true);
		return 0;
	}
	if(v.size()==n-1)
	{
		l=1;
		ans=1;
		for(int i=2;i<=n;i++)
		{
			if((a[i]-a[i-1])*(i-1)<=m)
			{
				m-=(a[i]-a[i-1])*(i-1);
				ans++;
			}
			else break;
		}
		write(ans,true);
		return 0;
	}
	for(long long i=0;i<v.size();i++)
	{
		//write(v[i],true);
		ans=max(ans,check(v[i]));
	}
	write(ans,true);
	return 0;
}
