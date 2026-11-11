#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long a,n;
    cin>>a>>n;
    while(n--)
    {
        long long aaa,bbb,s = a;
        cin>>aaa>>a;
        for(int i = 1;i<=aaa;i++)
        {
            cin>>a;
            s+=a;
            cin>>a;
            s-=(a/2);
        }
        cout<<s<<"\n";
    }
    return 0;
}
