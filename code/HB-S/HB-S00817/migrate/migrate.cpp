#include <bits/stdc++.h>
using namespace std;
int yl,zhusu;
int n,m;
struct mzl
{
    int dy;
}a[100005];
int book[100005];
int js[100005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>yl>>zhusu;
    for(int i=1;i<=zhusu;i++)
    {
        int cnt=0;
        memset(a,0,sizeof(a));
        cin>>n>>m;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j].dy;
            book[a[j].dy]=1;
        }
        int kskbl=a[n].dy;
        for(int j=1;j<=m;j++)
        {
            memset(js,0,sizeof(js));
            for(int k=a[j].dy+1;k<=min(a[j].dy+m,kskbl);k++)
            {
                if(book[k]!=0)
                {
                    for(int l=k+1;l<=min(k+m,kskbl);l++)
                    {
                        if(book[l]!=0)
                        {
                            js[l]++;
                        }
                    }
                }
            }
            for(int k=a[1].dy;k<=a[n].dy;k++)
            {
                if(js[k]==2)
                {
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
        memset(book,0,sizeof(book));
    }
    return 0;
}
