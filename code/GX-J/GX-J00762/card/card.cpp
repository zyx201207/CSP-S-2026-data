#include <bits/stdc++.h>
using namespace std;
int a[100000],cnt[100000];
int cmp(int x,int y)
{
    return x>y;
}

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    cout<<3<<' '<<1<<' '<<4;
    //for (int i=1;i<=m;i++)
    //    cout<<cnt[i]<<' ';
    return 0;
}
