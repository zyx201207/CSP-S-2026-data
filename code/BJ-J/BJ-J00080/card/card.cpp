#include<bits/stdc++.h>
using namespace std;
int cnt[300005];
int a[500005];
int table[500005];
bool used[500005];
bool have[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int t=1;t<=n;t++)
    {
        for(int i=1;i<500005;i++)
        {
            table[i]=0;
            used[i]=false;
        }
        for(int i=1;i<300005;i++)
            have[i]=false;
        int cnt1=0;
        for(int i=t;i<=n;i++)
        {
            bool flag=false;
            int pos=0;
            for(int j=i;j>=1;j--)
            {
                if(used[i])
                    continue;
                if(table[j]==a[i])
                {
                    flag=true;
                    pos=j;
                    break;
                }
            }
            if(flag)
            {
                table[++cnt1]=a[i];
                for(int j=cnt1-1;j>=pos;j--)
                    used[j]=true;
            }
        }
        for(int i=1;i<=cnt1;i++)
        {
            if(used[i]==true)
                continue;
            have[table[i]]=true;
        }
        for(int i=1;i<=m;i++)
            if(have[i])
                cnt[i]++;
    }
    for(int i=1;i<=m;i++)
        printf("%d ",cnt[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
