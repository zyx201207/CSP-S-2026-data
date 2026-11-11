#include<bits/stdc++.h>
using namespace std;

int n,m,card[500005],desk[500005],pos[300005],ans[500005];
bool have[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>card[i];
    }
    for (int i=1;i<=n;i++)
    {
        int cnt=0;
        for (int j=i;j<=n;j++)
        {
            if (have[card[j]])
            {
                int cnt2=cnt;
                for (int k=pos[card[j]];k<=cnt;k++,cnt2--)
                {
                    have[desk[k]]=false;
                    desk[k]=0;
                }
                cnt=cnt2;
            }
            desk[++cnt]=card[j];
            have[card[j]]=true;
            pos[card[j]]=cnt;
            //for (int k=1;k<=cnt;k++) cout<<desk[k]<<" ";
            //cout<<endl;
        }
        for (int j=1;j<=m;j++)
        {
            if (have[j]) ans[j]++;
        }
        for (int j=1;j<=max(n,m);j++)
        {
            have[j]=false;
            desk[j]=0;
            pos[j]=0;
        }

    }
    for (int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
