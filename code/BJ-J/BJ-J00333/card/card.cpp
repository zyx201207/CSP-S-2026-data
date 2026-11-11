#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
    int ju;
    int shu;
}desk[5000005];
int card[5000005],cnt[5000005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>card[i];
    }

    for (int i=1;i<=3000;i++)
    {
        cout<<card[1]<<" ";
    }
}
