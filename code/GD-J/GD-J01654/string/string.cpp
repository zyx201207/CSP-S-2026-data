#include<iostream>

using namespace std;
struct sb{
	char s;
	long long sl;
};
long long n;
sb a[300005];

long long f(long long pos,long long pre,long long cs)
{
	if(pre<=pos) return cs;
	
	if(a[pos].s!=a[pre].s)
	{
		if(a[pos].sl>=a[pre].sl)
		{
			if(a[pos].sl==a[pre].sl) 
			{
				return f(pos+1,pre-1,cs+a[pre].sl);
			}
			else
			{
				a[pos].sl-=a[pre].sl;
				return f(pos,pre-1,cs+a[pre].sl);
			}
		}
		else
		{
			a[pre].sl-=a[pos].sl;
			return f(pos+1,pre,cs+a[pos].sl);
		}
	}
	
	else
	{
		if(a[pos].sl>a[pre].sl)
		{
			a[pos].sl-=a[pre].sl;
			return f(pos,pre-1,cs);
		}
		else if(a[pos].sl==a[pre].sl) return f(pos+1,pre-1,cs);
		else
		{
			a[pre].sl-=a[pos].sl;
			return f(pos+1,pre,cs);		
		}
	} 
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].sl>>a[i].s;
	}
	cout<<f(1,n,0);
}
