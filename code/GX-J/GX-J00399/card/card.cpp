#include<bits/stdc++.h>
using namespace std;
long long a[500002],to[500002];
long long p[500002];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long n,m,i,j,t=0,k;
    cin>>n>>m;
    //cout<<n<<" "<<m;
    for(i=1;i<=n;i++)
        cin>>a[i];
    //for(i=1;i<=n;i++)cout<<p[i]<<endl;
   // p.clear();
    for(i=1;i<=m;i++)
    {
        for(j=i;j<=n;j++)
        {

            for(k=t-1;k>=0;k--)
                if(p[k]==a[j])t=k;
            p[t]=a[j];t++;
          //  for(j=0;j<t;j++)cout<<p[t]<<" ";
            //cout<<endl;
        }

        for(j=0;j<t;j++)to[p[j]]++;
       for(i=0;i<=500001;i++)p[i]=0;
    }
     for(i=1;i<=m;i++)cout<<to[i]<<" ";
     return 0;
}
