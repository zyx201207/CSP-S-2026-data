#include <bits/stdc++.h>
using namespace std;
string z[200005];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,g=0,zs=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a1;
        string a2;
        cin>>a1>>a2;
        zs+=a1;
        for(int j=0;j<a1;j++) z[g++];
    }
    int b=zs/2,cnt=0;
    for(int i=0;i<b;i++)
    {
        if(z[i]!=z[zs-i]) cnt++;
    }
    cout<<cnt;
    return 0;
}

