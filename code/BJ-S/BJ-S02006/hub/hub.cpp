#include<bits/stdc++.h>
using namespace std;
int a[(int)1e6+10];
signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    srand(time(0));
    while(t--)
    {
        cout<<rand()%rand()/(rand()%rand()+1)%rand()<<endl;
    }
    return 0;
}
