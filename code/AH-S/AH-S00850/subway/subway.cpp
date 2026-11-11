#include<bits/stdc++.h>
using namespace std;
long long s[500015];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,p;
    cin>>c>>n>>m>>d>>p;
    for(int i = 1;i <= m;i++)
    {
        cin>>s[i];
    }
    for(int i = 1;i <= n;i++)
    {
        long long k;
        cin>>k;
        for(int i = 1;i <= 2*k;i++)
        {
            long long a;
            cin>>a;
        }
    }
    for(long long i = 1;i <= p;i++)
    {
        long long x,y;
        cin>>x>>y;
        cout<<s[x] + s[y]<<endl;
    }


    return 0;
}
