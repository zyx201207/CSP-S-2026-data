#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x[200005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        int ans=0;
        cout<<(n+1)/d-d+1<<endl;
    }
    return 0;
}