#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,M=1e8;
int a[N],L,ans;
string s="";
char c[N];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n=read();
    for(int i=1;i<=n;i++)
    {
		a[i]=read();
		cin>>c[i];
		L+=a[i];
		if(n*a[i]<=M)
			for(int j=1;j<=a[i];j++)
				s+=c[i];
		else break;
	}
	for(int i=1;i<=L;i++)
	{
		if(s[i-1]!=s[L-i])
		{ans++;s[i-1]=s[L-i];}
	}
	cout<<ans<<endl;
    return 0;
}
//68
