#include <bits/stdc++.h>
using namespace std;
string t;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            t+=c;
        }
    }
    long long s=0;
    long long l=t.size();
    for(long long i=0;i<l/2;i++)
    {
        if(t[i]==t[l-i-1])
        {
            s++;
        }
    }
    cout<<l/2-s;
    return 0;
}
