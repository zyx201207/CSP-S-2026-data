#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,y;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a>=2)
        {
            y++;
        }
    }
    cout<<y;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    return 0;
}
