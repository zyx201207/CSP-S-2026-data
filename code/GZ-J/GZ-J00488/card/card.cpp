//GZ-J00488 ·½Åæç÷
#include <bits/stdc++.h>
int n,m,a[50005],cnt[30005];
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int b[30005]={},have[30005]={};
        int cntb=0;
        int now=0;
        for(int j=i;j<=n;j++)
        {
            now++;
            if(have[a[j]]!=0)
            {
                for(int k=have[a[i]]+1;k<=now;k++)
                {
                    b[k]=0;
                }
                cntb=have[a[j]];
                now=have[a[j]];
            }
            have[a[j]]=now;
            b[now]=a[j];

            cntb++;
        }
        for(int j=1;j<=cntb;j++)
            cnt[b[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
