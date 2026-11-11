#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,q;cin>>c>>q;
    for(int i=1;i<=q;i++)
    {
        int n,m;cin>>n>>m;
        for(int i=1;i<n;i++)
        {
            int a;cin>>a;
            cin>>a;
        }
        cout<<n/2<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
