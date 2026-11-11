#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++)
    {
        cnt++;
        if(a[i]!=a[i+1])  printf("%d ",cnt);
    }
    cout<<++cnt;
    return 0;
}
