#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[m+2],b[n+2],ss[m+2];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=m;i++)
    {
        ss[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        int s=0;
        for(int j=i;j<=n;j++)
        {
            a[s+1]=b[j];
            s++;
            for(int k=1;k<s;k++)
            {
                if(a[k]==a[s])
                {
                    s=k;
                }
            }
        }
        for(int j=1;j<=s;j++)
        {
            ss[a[j]]++;
        }
        cout<<endl;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ss[i]<<" ";
    }
    return 0;
}
