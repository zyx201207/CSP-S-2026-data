#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N],b[N],c[M],Max;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int len=1;
        bool f=false;
        for(int j=i;j<=n;j++)
        {
            int k=a[j];
            for(int l=1;l<=len;l++)
                if(b[l]==k)
                {
                    for(int x=l;x<=len;x++) b[x]=0;
                    len=l-1;
                    break;
                }
            b[len+1]=k;
            len++;
        }
        for(int j=1;j<=len;j++)
        {
            c[b[j]]++;
            Max=max(Max,b[j]);
        }
        for(int j=1;j<=len;j++) b[j]=0;
    }
    for(int i=1;i<=Max;i++) cout<<c[i]<<" ";
    return 0;
}
