#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    //if (c==11||c==12||c==0)
    //{
        while (t--)
        {
            int n,d;
    long long A,B;
            cin>>n>>d;
            if (d==1||n<=3)
            {
                cout<<0<<endl;
                continue;
            }
            cin>>A>>B;
            cout<<max(0ll,n-1ll*2*(d/abs(A-B))+1)<<endl;
        }
    //}

    return 0;
}
