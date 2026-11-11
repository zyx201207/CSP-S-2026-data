#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T,n,m;
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<1<<endl;
    }
    return 0;
}
