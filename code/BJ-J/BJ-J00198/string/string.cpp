#include<bits/stdc++.h>
using namespace std;
long long a[100000];
char c;
long long l;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans;
    cin>>n;
    string t;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c;
        for(int j=1;j<=a[i];j++)
        {
            t+=c;
            l++;
        }
    }

    for(int i=0;i<l;i++)
    {
        if(t[i]!=t[l-i]) ans++;
    }
    cout<<ans;
    return 0;
}
