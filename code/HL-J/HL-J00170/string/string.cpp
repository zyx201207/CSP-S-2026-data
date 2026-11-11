#include <bits/stdc++.h>
using namespace std;
long long n,sum;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long a;
        char b;
        cin>>a>>b;
        for(int j=1;j<=a;j++)
        {
            s+=b;
        }
    }
    for(int i=0;i<=s.size()-1;i++)
    {
        if(s[i]!=s[s.size()-i-1])
        {
            s[s.size()-i-1]=s[i];
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
