#include <iostream>
#include <cstdio>
using namespace std;
char c[200005];
long long ans;
string s;
int p,q,m,n,t,x[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int b;
	cin>>b;
	for(int i=0;i<b;i++)
	{
		cin>>x[i]>>c[i];
	}
	while(p<b-1-q)
	{
		if(t==0) m=x[p],n=x[b-1-q];
		else if(t==1) m=x[p];
		else n=x[b-1-q];
		if(c[p]!=c[b-1-q])
		{
			if(m<n)
			{
				ans+=m;
				n-=m;
				p++;
				t=1;
			}
			else if(m>n)
			{
				ans+=n;
				m-=n;
				q++;
				t=2;
			}
			else
			{
				ans+=m;
				p++;
				q++;
				t=0;
			}
		}
		else
		{
			if(m<n)
			{
				n-=m;
				p++;
				t=1;
			}
			else if(m>n)
			{
				m-=n;
				q++;
				t=2;
			}
			else
			{
				p++;
				q++;
				t=0;
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
