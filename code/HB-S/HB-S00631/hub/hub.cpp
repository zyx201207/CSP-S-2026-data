
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
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
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            cin>>u>>v;
        }
        int m=(n-1)/2;
        cout<<1+max(0,int(ceil((m*1.0-k*1.0)/4)))<<endl;
    }
    return 0;
}
/*
最后半个小时，不打暴力了，脑测了个特殊性质
*/
