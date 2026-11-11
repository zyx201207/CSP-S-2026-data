#include <bits/stdc++.h>
using namespace std;
struct Card
{
    int where;//0 未打出 1 桌面 2 收回
    int num;
};
Card card[500005];
int a[300005];
int d[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        cin>>card[i].num;
        card[i].where=0;
    }
    for(int r=1;r<=n;++r)
    {
        int desk=0;
        for(int i=0;i<n;++i)
        {
            card[i].where=0;
            d[i]=-1;
        }
        for(int i=r;i<=n;++i)
        {
            for(int j=0;j<desk;++j)
            {
                if(d[j]==card[i].num)
                {
                    for(int k=j;k<desk;++k)
                    {
                        d[j]=-1;
                        desk--;
                    }
                }
            }
            card[i].where=1;
            desk++;
            d[desk]=card[i].num;
            for(int l=1;l<=m;++l)
            {
                for(int k=0;k<desk;++k)
                {
                    if(d[k]==l)
                    {
                        a[l]++;
                    }
                }
            }
        }
    }
    for(int i=0;i<m;++i)
    {
        cout<<a[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
