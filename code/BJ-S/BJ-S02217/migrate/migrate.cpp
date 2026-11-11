#include<bits/stdc++.h>
using namespace std;
long long x[2000010];
vector<vector<long long>> dp(2000010,vector<long long>(2000010));
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n;
        long long d;
        cin>>n>>d;
        for(long long i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

