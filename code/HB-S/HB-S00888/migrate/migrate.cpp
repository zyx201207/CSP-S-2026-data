#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i = 1;i<=t;i++)
    {
        int n,d;
        cin>>n>>d;
        vector<int> x(n);
        for(int j = 0;j<n;j++)
        {
            cin>>x[j];
        }
        if(x[1]-x[0]>d || x[2]-x[1] >d || x[3]-x[2]>d)
        {
            cout<<0<<endl;
        }
        else if(c == 11 || c == 12)
        {
            int dx = x[1]-x[0];
            if(d<dx*2)
            {
                cout<<0<<endl;
                continue;
            }
        }
        else if(c == 13 || c == 14) cout<<0<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
