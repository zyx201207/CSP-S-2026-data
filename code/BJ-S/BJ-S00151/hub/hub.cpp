#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,t,dp[2000006];
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    srand(time(0));
    cin>>c>>t;
    while(t--)
    {
        cout<<rand()%10<<'\n';
    }
    return 0;
}
//0 1 2 3 4
//0 1 2 3 4 5
//0 1 2 3 4 5 6 7 8 9