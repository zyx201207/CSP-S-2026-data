#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    for(int i=1; i<=n; i++)
    {
        int bo[500005];
        bool vis[300005]={false};
        int tmp;
        for(int j=i; j<=n; j++)
        {
            if(vis[a[j]])
            {
                int f=1;
                for(int k=1; k<=j-i; k++)
                {
                    if(bo[k]==a[j]) f=0;
                    if(f==0)
                    {
                        vis[bo[k]]=false;
                        bo[k]=0;
                    }

                }
            }
            bo[j-i+1]=a[j];
            vis[a[j]]=true;
            if(j==n) tmp=j-i+1;
        }
        for(int j=1; j<=tmp; j++)
        {
            b[bo[j]]++;
        }
    }
    for(int i=1; i<=m; i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}
