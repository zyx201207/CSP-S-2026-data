#include<iostream>
#define int long long
using namespace std;
const int N=2e6+10,M=5e3+10;
int c,T,n,d,a[N],f[M][M];
int read()
{
  int res=0,f=1;
  char ch=getchar();
  while(ch<'0'||'9'<ch)
  {
    if(ch=='-')f=-1;
    ch=getchar();
  }
  while('0'<=ch&&ch<='9')
  {
    res=res*10+ch-'0';
    ch=getchar();
  }
  return res*f;
}
signed main()
{
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  c=read(),T=read();
  while(T--)
  {
    n=read(),d=read();
    for(int i=1; i<=n; ++i)a[i]=read();
    if(n==1)
    {
      cout<<"0\n";
      continue;
    }
    if(c==11||c==12)//A
    {
      int delta=a[2]-a[1];
      if(d<2*delta)cout<<"0\n";
      else cout<<n-3<<'\n';
      continue;
    }
    if(c==13||c==14)//B
    {
      cout<<0<<'\n';
      continue;
    }
    int ans=0;
    for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j)f[i][j]=0;
    for(int i=1; i<=n; ++i)
    {
      f[i][i]=1;
      for(int j=i+1; j<=n; ++j)
      {
        for(int k=i; k<j; ++k)if(a[j]-a[k]<=d)
          {
            f[i][j]+=f[i][k];
          }
        if(f[i][j]==2)++ans;
        else if(f[i][j]>2)break;
      }
    }
    cout<<ans-1<<'\n';
  }
  return 0;
}
