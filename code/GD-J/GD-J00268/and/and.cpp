#include<bits/stdc++.h>
using namespace std;
int n,a[200005][41],m,b[200005],mx,idx;
struct u
{
	bool z,o;
	int zi,oi,s;
}t[6000005];
void add(long long n,int i)
{
	int deep=0,x=1;
	while(n>0)
	{
		a[i][x]=n%2;
		n/=2;
		x++;
	}
	b[i]=x-1;
}
void f(int u)
{
	int p=0,k=0,pow=1;
	for(int i=1;i<=b[u];i++)
	{
		k=k+pow*a[u][i];
		pow*=2;
		if(a[u][i]==0)
		{
			//cout<<0<<"   ";
			if(t[p].z)
			{
				t[p].s++;
				if(t[p].s>=m)mx=max(mx,k);
				//cout<<p<<"->"<<t[p].zi<<" 1\n";
				p=t[p].zi;
			}
			else
			{
				t[p].z=true;
				t[p].zi=idx+1;
				t[idx].s=1;
				if(t[p].s>=m)mx=max(mx,k);
				//cout<<idx<<"->"<<idx+1<<"\n";
				idx++;
				p=idx;
			}
		}
		else
		{
			//cout<<1<<"     ";
			if(t[p].o)
			{
				t[p].s++;
				if(t[p].s>=m)mx=max(mx,k);
				//cout<<p<<"->"<<t[p].oi<<" 1\n";
				p=t[p].oi;
			}
			else
			{
			    t[p].o=true;
				t[p].oi=idx+1;
				t[idx].s=1;
				if(t[p].s>=m)mx=max(mx,k);
				//cout<<idx<<"->"<<idx+1<<"\n";
				idx++;
				p=idx;
			}
		}
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>m;
	if(m==1)
	{
		for(int i=1;i<=n;i++)
	    {
	    	long long x;
	    	cin>>x;
	    	mx=max(mx,x);
	    }
	}
	else
	{
		for(int i=1;i<=n;i++)
	    {
	    	long long x;
	    	cin>>x;
    		add(x,i);
    		f(i);
    	}
	}
	cout<<mx;
	return 0;
} 
