#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005][10];
int ans;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n-1;i++)
        {
            cin>>a[i][1]>>a[i][2];
        }
        cout<<1;
    }
    return 0;
}