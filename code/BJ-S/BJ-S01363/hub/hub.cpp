#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,t,n,k,head[N],pos;
struct Node
{
    int v,nxt;
};
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>k;
        if(n<=k) cout<<"0\n";
        else cout<<"1\n";
    }
    return 0;
}
