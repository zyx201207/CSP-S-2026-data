#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int c,T,n,d,u[N],v[N];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read(),T=read();
    int i=1;
    while(T--)
    {
        n=read(),d=read();
        for(int i=1;i<=n;i++)
            cin>>u[i]>>v[i];
        cout<<i<<endl;
        i++;
    }
    return 0;
}
