#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
const int MAXM=3e5+10;
int n,m;
int a[MAXN];
int dt[MAXN];
int ans[MAXM];
int has[MAXM];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) dt[j]=0;
        for(int j=1;j<=m;j++) has[j]=0;
        int now=0;
        for(int j=i;j<=n;j++)
        {
            if(!has[a[j]])
            {
                dt[++now]=a[j];
                has[a[j]]=1;
            }
            else
            {
                for(int k=1;k<=now;k++)
                {
                    if(dt[k]==a[j])
                    {
                        for(int l=k+1;l<=now;l++)
                        {
                            has[dt[l]]=0;
                            dt[l]=0;
                        }
                        now=k;
                        break;
                    }
                }
            }
        }
        for(int j=1;j<=now;j++)
        {
            ans[dt[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
