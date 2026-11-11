#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int ui,vi;
        for(int i=1;i<=n;i++) cin>>ui>>vi;
        cout<<n-k<<endl;
    }
    return 0;
}