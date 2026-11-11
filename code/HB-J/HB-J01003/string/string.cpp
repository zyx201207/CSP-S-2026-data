#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    signed long long n,m=0,d=0;
    string a;
    cin>>n;
    if(n==1)
    {
            cout<<"0";
            return 0;
    }
    for(signed long long i=1;i<=n;i++)
    {
        signed long long b;
        string c;
        cin>>b>>c;
        d+=b;
        for(signed long long j=1;j<=b;j++)
        {
            a+=c;
        }
    }
    signed long long l=0,r=d-1;
    while(l<=r)
    {
        if(a[l]!=a[r])m++;
        l++,r--;
    }
    cout<<m;
    return 0;
}
