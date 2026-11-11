#include <bits/stdc++.h>

using namespace std;

long long n,a[100000000],c;
string s;
char b;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b;
        s[i]=b;
    }
    if(n%2==0)
    {
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-1-i])
            {
                cout<<s[i]<<"!="<<s[n-1-i]<<endl;
                if(a[i]>a[n-1-i])
                {
                    c+=a[n-1-i];
                }
                else
                {
                    c+=a[i];
                }
            }
        }
    }
    else
    {
        for(int i=0;i<=n/2;i++)
        {
            if(s[i]!=s[n-1-i])
            {
                if(a[i]<a[n-1-i])
                {
                    c+=a[n-1-i];
                }
                else
                {
                    c+=a[i];
                }
            }
        }
    }
    cout<<c;
    return 0;
}
