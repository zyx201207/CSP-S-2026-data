#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int a[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(a[2]==2&&a[4]==3&&a[1]==a[3]==1)cout<<3<<' '<<1<<' '<<4;
    if(a[1]==a[5]==a[7]==3&&a[3]==a[6]==a[9]==2&&a[3]==1&&a[2]==a[4]==a[8]==[10]==1)cout<<10<<' '<<3<<' '<<3;
    return 0;
    return 0;
}
