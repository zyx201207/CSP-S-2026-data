#include <bits/stdc++.h>
using namespace std;

int n,a,sum;
string s;
char b;
long long ans;

int main()
{
    //"delete '//'
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;//chu shi hua s
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        for(int j=1;j<=a;j++)
            s+=b;
    }
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[n-i])
            sum++;
    }
    cout<<sum;
    return 0;
}
