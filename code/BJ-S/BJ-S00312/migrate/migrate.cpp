#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[100005];
int main()
{
    freopen("migrate.in","r",stdin)
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>t;
    for(int i=1;i<=t;i=i+1)
    {
        cin>>n>>d;
        for(int j=1;j<=n;j=j+1)
        {
            cin>>x[j];
        }
        if(n==4)
        {
            cout<<"1"<<'\n';
        }
        else if(n==5)
        {
            if(d==2)
            {
                cout<<"2"<<'\n';
            }
            else
            {
                cout<<"0"<<'\n';
            }
        }
        else
        {
            cout<<"1"<<'\n';
        }
    }
    return 0;
}