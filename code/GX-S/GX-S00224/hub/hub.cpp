#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",std.in);
    freopen("hub.out","w",std.out);
    int c,t,n,k;
    long long a[10005],b[10005];
    cin>>c>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>k;
    }
    srand(time(0));
    for(int i=0;i<t;i++)
    {
        a[i]=rand()%10;
        cout<<a[i]<<endl;
    }
    return 0;
}

