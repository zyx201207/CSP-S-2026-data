#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long a,n;
    cin>>a>>n;
    while(n--)
    {
        long long aaa,bbb,s = 0;
        cin>>aaa>>a;
        for(int i = 1;i<=aaa;i++)
        {
            s+=a;
            cin>>a;
        }
        cout<<s<<"\n";
    }
    return 0;
}
