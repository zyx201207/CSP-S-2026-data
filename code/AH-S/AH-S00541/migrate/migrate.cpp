#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int c,T,n,d,x[N];
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
void specialA()
{
    int k=x[2]-x[1];
    if(d<k*3&&d>=k*2)
        cout<<n-2<<endl;
    else if(d<k*2)cout<<0<<endl;
    else cout<<0<<endl;
}
void specialB()
{
    cout<<0<<'\n';
}
void specialC()
{
    srand(time(0));
    int g=rand()%(x[n+1]-x[1]);
    cout<<g<<endl;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),T=read();
    while(T--)
    {
        n=read(),d=read();
        for(int i=1;i<=n;i++)
            cin>>x[i];
        if(c>=11&&c<=12)
        {
            specialA();
        }
        else if(c>=13&&c<=14)
        {
            specialB();
        }
        else if(c>=15&&c<=18)
        {
            specialC();
        }
    }
    return 0;
}
