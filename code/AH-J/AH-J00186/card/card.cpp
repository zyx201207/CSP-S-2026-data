#include<bits/stdc++.h>
using namespace std;
int i,j,k,js[100005],a[200000],p[200000];
int n,m,b,p1;
int hx[200000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        p1=0;
        memset(p,0,sizeof(p));
        memset(hx,0,sizeof(hx));
        for(j=i;j<=n;j++)
        {
           b=a[j];
           if(hx[b]!=0)
           {
               p1=hx[b];
               for(k=hx[b];k<=j;k++)
               {
                   p[k]=0;
               }
               p[p1]=0;
           }
           else
           {
               p1++;
               p[p1]=a[j];
               hx[b]=1;
           }
        }
        for(j=1;j<=n;j++)
        {
            if(p[j]>0)js[p[j]]++;
        }
    }
    for(i=1;i<=m;i++)
        cout<<js[i]<<" ";
    return 0;
}
