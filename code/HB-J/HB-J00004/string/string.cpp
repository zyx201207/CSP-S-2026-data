#include<bits/stdc++.h>
using namespace std;
int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return x;
}
int a[200001];
char c[200001];
int main()
{
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
    int n;
    n=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        cin>>c[i];
    }
    int l=1,r=n;
    long long ans=0,sum1=a[1],sum2=a[n];
    while(l<r)
    {
        if(c[l]==c[r])
        {
            if(sum1==sum2) l++,r--,sum1=a[l],sum2=a[r];
            else if(sum1>sum2) sum1-=sum2,r--,sum2=a[r];
            else if(sum1<sum2) sum2-=sum1,l++,sum1=a[l];
        }
        else
        {
            if(sum1==sum2) ans+=sum1,l++,r--,sum1=a[l],sum2=a[r];
            else if(sum1>sum2) ans+=sum2,sum1-=sum2,r--,sum2=a[r];
            else if(sum1<sum2) ans+=sum1,sum2-=sum1,l++,sum1=a[l];
        }
    }
    cout<<ans;
    return 0;
}
