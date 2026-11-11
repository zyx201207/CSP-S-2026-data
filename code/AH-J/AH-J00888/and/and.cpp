#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],c[N],n,m,ans;
int b[N];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		c[i]=a[i];
	}
	if(m==1)
	{
		sort(a+1,a+1+n);
		cout<<a[n+1]<<endl;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{int x=a[i]&a[j];ans=max(ans,x);}
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
		a[i]^=a[i-1],c[i]|=c[i-1];
	for(int i=1;i<=n;i++)
		b[i]=c[i]-a[i];
	for(int i=n;i>=n-m+1;i--)
		if(b[i-m]!=0)ans=max(ans,b[i]-b[i-m]);
	cout<<ans<<endl;
    return 0;
}
//20+?
