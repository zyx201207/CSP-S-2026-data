#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],c[N],n,m,ans,f;
int one,two;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
bool find(int x)
{
	int l=1,r=ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(c[mid]==x){f=mid;return false;}
		if(c[mid]>x)r=mid;
		else l=mid+1;
	}
	return true;
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	if(m==1){cout<<n<<endl;return 0;}
	if(m==2)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(find(a[j])==true)c[++ans]=a[j];
				else 
				{
					for(int k=f;k<=ans;k++)
						c[k]=0;
					c[f]=a[j];
				}
			}
			if(find(1)==false)one++;
			if(find(2)==false)two++;
			memset(c,0,sizeof(c));
		} 
		cout<<one<<" "<<two;
		return 0;
	}
	for(int i=1;i<=n;i++)
		cout<<i<<" ";
    return 0;
}
//20
//ZHALE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
