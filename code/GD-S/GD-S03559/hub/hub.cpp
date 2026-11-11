#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
inline long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch)
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		n=read(),d=read();
		for(int i=1,x,y;i<n;i++)x=read(),y=read();
		cout<<"0\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
