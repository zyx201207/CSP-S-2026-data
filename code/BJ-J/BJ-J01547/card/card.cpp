#include <bits/stdc++.h>
using namespace std;
int card_all[500005],a[5000005];
struct one{
    int shu;
    bool vis=0;
    int dizhi;
}card_new[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>card_all[i];
    }
    for(int i=1;i<=n;i++)
    {
        int cnt=1;
        for(int j=i-1;j<=n;j++)
        {
            if(card_new[card_all[j]].vis==1)
            {
                int num=0;
                for(int z=1;z<=m;z++)
                {
                    if(card_new[z].dizhi>=card_new[card_all[j]].dizhi)
                    {
                        card_new[z].vis=0;
                        card_new[z].dizhi=0;
                        num++;
                    }
                }
                cnt=cnt-num+1;
                card_new[card_all[j]].vis=1;
                card_new[card_all[j]].dizhi=cnt;
                cnt++;
            }
            else{
                card_new[card_all[j]].vis=1;
                card_new[card_all[j]].dizhi=cnt;
                cnt++;
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(card_new[j].vis==1)
            {
                a[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(a[i])
        {
            cout<<a[i]<<" ";
        }
    }
    return 0;
}
