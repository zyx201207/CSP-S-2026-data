#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int w[500005];
    int v[500005];
    int s[500005];
    int e[500005];
    while(t--)
    {
        memset(w,0,sizeof(w));
        memset(v,0,sizeof(v));
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>w[i]>>v[i];
            s[w[i]]++;
            e[v[i]]++;
        }

    }
    return 0;
}
