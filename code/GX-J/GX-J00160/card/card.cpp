#include <bits/stdc++.h>
using namespace std;


int main()
{

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int hand[n+1]={0};
    int desk[n+1]={0};
    int cnt[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>hand[i];
    }
    int b=1,sum=1;
    while(b<=m)
    {
        for(int i=b;i<=n;i++)
        {
            desk[sum]=hand[i];
            for(int j=1;j<=sum;j++)
            {
                if(desk[j]==desk[sum])
                {
                    sum=j;
                    for(int k=j;k<sum;k++)
                    {
                        desk[k]=0;
                    }
                }
            }
            sum++;
        }
        for(int i=1;i<=n;i++)
        {
            cnt[desk[i]]++;
        }
        b++;
    }
    cnt[hand[n]]=n;
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
