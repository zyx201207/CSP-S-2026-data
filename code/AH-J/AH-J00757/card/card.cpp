#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[6035533],v[6035533],n,m,mah[6035533];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)v[i]=0;
        for(int j=i;j<=n;j++)
        {
            for(int k=j-1;k>=i;k--)
            {
                if(a[k]==a[j]&&v[k]==0&&v[j]==0)
                {
                    for(int p=k;p<j;p++)v[p]=1;
                    break;
                }
            }
        }
       // if(i==2||i==3||i==6)cout<<"\n";
       // cout<<i<<": ";
        for(int k=i;k<=n;k++)
        {
            //cout<<v[k]<<' '<<a[k]<<endl;
            if(v[k]==0)mah[a[k]]++;
      //      if(v[k]==0)cout<<a[k]<<' ';
        }
      //  cout<<endl;
    }
    for(int i=1;i<=m;i++)cout<<mah[i]<<"\n";
    return 0;
}
//green No Ac   No Time  About 50 point?
//It is not difficult,but TLE
