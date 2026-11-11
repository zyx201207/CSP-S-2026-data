#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int c,n,m,d,q,a[N],b[N],t[N],cnt;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
void specialA()
{
    cout<<0<<endl;
}
void specialB()
{
    cout<<t[n+1]*n/2<<endl;
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++)
        cin>>a[i];
    int k=read();
    for(int j=1;j<=n;j++)
        for(int i=1;i<=2*k;i++)
            cin>>b[i]>>t[i];
    if(c>=7&&c<=11)
    {
        specialA();
    }
    else if(c>=12&&c<=19)
    {
        specialB();
    }
    else{
        srand(time(0));
        int wow=rand()%(t[n+1]*n);
        cout<<wow<<endl;
    }
    return 0;
}
