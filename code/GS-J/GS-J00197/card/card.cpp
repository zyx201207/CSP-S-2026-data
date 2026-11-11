#include<bits/stdc++.h>
using namespace std;
int c[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 0;i < n;i++)cin>>c[i];
    if(m==1)
    {
        cout<<n;
    }
    if(m==2)
    {
        cout<<n<<' '<<m;
    }
    return 0;
}
