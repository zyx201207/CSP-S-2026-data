#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[5005]; 
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')if(c=='-')f=-1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
    	a[i]=read();
	}
	a[n+1]=-1;
	for(int i=2;i<=n+1;i++){
		if(a[i]!=a[i-1])cout<<i-1<<' ';
	}
    return 0;
}
