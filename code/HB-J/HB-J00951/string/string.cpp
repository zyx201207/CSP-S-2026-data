#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long m[n+5];
    char a[n+5];
    for(int i=1;i<=n;i++)
    {
        cin>>m[i];
        cin>>a[i];
    }
    char c=a[1];
    long long s=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=c)
        {
            s+=m[i];
            c=0;
        }
    }
    if(c==0)
    {
        cout<<s;

    }
    else{
        cout<<0;
    }
    return 0;
}
