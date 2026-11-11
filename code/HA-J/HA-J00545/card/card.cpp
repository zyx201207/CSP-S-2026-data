#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a=0;
	cin>>a;
	cout<<a%2<<" "<<a%2<<" "<<a%2;
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c<'9'&&c>'0')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	cout<<n;
}*/
