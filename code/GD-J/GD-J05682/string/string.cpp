#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=2e5+5;
int n,ai[N];
char a[N];
void solve()
{
	ll total_len=0,Cyrene=0,Elysia=0;
	bool f=false,fm=false;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ai[i]>>a[i];
		total_len+=ai[i];
	}
	if(total_len%2) f=true;
	vector<int> vi;
	vector<char> v;
	int rem=0,pos,s=0,m=total_len/2;
	char remc;
	//left
	for(int i=1;i<=n;i++)
	{
		if(s+ai[i]==m) 
		{
			vi.pb(ai[i]);
			v.pb(a[i]);
			pos=i+1;
			if(f) fm=true;
			break;
		}
		if(f&&s+ai[i]==m+1)
		{
			vi.pb(ai[i]-1);
			v.pb(a[i]);
			pos=i+1;
			break;
		}
		if(s+ai[i]>m) 
		{
			if(!f) vi.pb(m-s),rem=rem+(s+ai[i]-m),remc=a[i];
			else vi.pb(m-s-1),rem=rem+(s+ai[i]-m-1),remc=a[i];
			v.pb(a[i]);
			pos=i+1;
			break;
		}
		s+=ai[i];
		vi.pb(ai[i]);
		v.pb(a[i]);
	}
	int len=v.size(),temp=0;
	char tempc;
	for(int i=0,j=len-1;i<j;i++) swap(vi[i],vi[j]),swap(v[i],v[j]);
	remc=a[pos];
	for(int i=pos,j=0;i<=n;i++)
	{
		while(rem>0)
		{
			if(rem>=vi[j])
			{
				if(remc!=v[j]) Cyrene+=rem-vi[j];
				rem-=vi[j],j++;
			} 
			else 
			{
				temp=vi[j]-rem,tempc=v[j],rem=0;
				if(remc!=v[j]) Cyrene+=temp;
			}
		}
		if(fm)
		{
			if(ai[i]>=temp+1)
			{
				if(tempc!=a[i]) Cyrene+=ai[i]-temp;
				rem=ai[i]-temp-1,remc=a[i],j++;
			}	 
			else 
			{
				if(tempc!=a[i]) Cyrene+=temp-ai[i];
				temp-=ai[i]+1;
			}
			fm=false;
		}
		else
		{
			if(ai[i]>=temp)
			{
				if(tempc!=a[i]) Cyrene+=ai[i]-temp;
				rem=ai[i]-temp,remc=a[i],j++;
			}	 
			else 
			{
				if(tempc!=a[i]) Cyrene+=temp-ai[i];
				temp-=ai[i];
			}
		}
	}
	for(int i=0;i<len;i++) v[i]=' ',vi[i]=0;
	rem=0,pos,s=0,temp=0,fm=false;
	//right
	for(int i=n;i>=1;i--)
	{
		if(s+ai[i]==m) 
		{
			vi[i]=ai[i];
			v[i]=a[i];
			pos=i-1;
			if(f) fm=true;
			break;
		}
		if(f&&s+ai[i]==m+1)
		{
			vi[i]=ai[i]-1;
			v[i]=a[i];
			pos=i-1;
			break;
		}
		if(s+ai[i]>m) 
		{
			if(!f) vi[i]=(m-s),rem=rem+(s+ai[i]-m),remc=a[i];
			else vi[i]=(m-s-1),rem=rem+(s+ai[i]-m-1),remc=a[i];
			v[i]=a[i];
			pos=i-1;
			break;
		}
		s+=ai[i];
		vi[i]=ai[i];
		v[i]=a[i];
	}
	for(int i=0,j=len-1;i<j;i++) swap(vi[i],vi[j]),swap(v[i],v[j]);
	remc=a[pos];
	for(int i=pos,j=0;i>=1;i--)
	{
		while(rem>0)
		{
			if(rem>=vi[j])
			{
				if(remc!=v[j]) Elysia+=rem-vi[j];
				rem-=vi[j],j++;
			} 
			else 
			{
				temp=vi[j]-rem,tempc=v[j],rem=0;
				if(remc!=v[j]) Elysia+=temp;
			}
		}
		if(fm)
		{
			if(ai[i]>=temp+1)
			{
				if(tempc!=a[i]) Elysia+=ai[i]-temp;
				rem=ai[i]-temp-1,remc=a[i],j++;
			}	 
			else 
			{
				if(tempc!=a[i]) Elysia+=temp-ai[i];
				temp-=ai[i]+1;
			}
			fm=false;
		}
		else
		{
			if(ai[i]>=temp)
			{
				if(tempc!=a[i]) Elysia+=ai[i]-temp;
				rem=ai[i]-temp,remc=a[i],j++;
			}	 
			else 
			{
				if(tempc!=a[i]) Elysia+=temp-ai[i];
				temp-=ai[i];
			}
		}
	}
	cout<<min(Cyrene,Elysia);
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
	while(T--) solve();
	return 0;	
} 
