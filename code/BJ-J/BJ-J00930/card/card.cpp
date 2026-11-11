#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000010

ll n,m;
ll tong[N];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(ll i=1,x;i<=n;i++)
    {
        cin>>x;
        tong[x]+=i;
    }

    for(int i=1;i<=m;i++)
    {
        cout<<tong[i]<< " ";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
