#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a[130000]={""},s,ds="";
    long long n,b[300000]={0},sum=0;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> b[i] >> a[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=b[i];j++)
        {
            s+=a[i];
        }
    }
    ds=s;
    reverse(s.begin(),s.end());
    if (s==ds)
    {
        cout << 0;
        return 0;
    }
    for (int i=1;i<=s.length();i++)
    {
        if (s[i-1]==s[s.length()-i])
        {
            sum=sum;
        }
        else
        {
            s[i-1]=s[s.length()-i];
            sum++;
        }
    }
    cout << sum;
    return 0;
}
