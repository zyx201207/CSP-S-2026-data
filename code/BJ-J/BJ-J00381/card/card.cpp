#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],pos[300005],ans[300005];
bool flag[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++) flag[j]=1;
        for(int j=i;j<=n;j++)
        {
            if(!pos[a[j]]) pos[a[j]]=j;
            else
            {
                for(int k=pos[a[j]];k<j;k++)
                {
                    if(flag[k])
                    {
                        flag[k]=0;
                        pos[a[k]]=0;
                    }
                }
                pos[a[j]]=j;
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(pos[j]) ans[j]++;
            pos[j]=0;
        }
    }
    for(int i=1;i<=m;i++) cout << ans[i] << " ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
