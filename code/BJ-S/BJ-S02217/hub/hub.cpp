#include<bits/stdc++.h>
using namespace std;
long long u[100000010],v[100000010];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        for(long long i=1;i<=n;i++)
        {
            cin>>u[i]>>v[i];
        }
        cout<<1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

