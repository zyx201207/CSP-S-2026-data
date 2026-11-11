#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],s[300005],vis[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
    int t=1;
    while(t++)
    {
        int j=1;
        for(int i=t;i<=n;i++)
            {
                int k;
                for(k=1;k<=j;k++)
                    {
                        if(b[k]==a[i])
                            {
                                break;
                            }
                    }
                if(k>j)
                    {
                        b[j++]=a[i];
                    }
                else
                    {
                        j=k;
                    }
            }
        for(int i=1;i<=j;i++)
            {
                if(vis[i])
                    {
                        s[b[i]]+=1;
                        vis[i]=1;
                    }
            }
    }
    for(int i=1;i<=m;i++)
        {
            cout<<s[i]<<" ";
        }
    return 0;
}
