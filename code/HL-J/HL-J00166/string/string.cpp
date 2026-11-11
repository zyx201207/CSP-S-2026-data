#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a;

    string s;

    cin >> a;
    for (int i=1; i<=a; i++)
    {
        long long x=0;
        string b;
        cin >> x >> b;
        for (int j=1; j<=x; j++)
        {
            s+=b;
        }


    }


    string sum;
    long long n,cnt=0,c=0;

    n=s.size();
    for (int i=n-1; i>=0; i--)
    {
        sum[c]=s[i];
        c++;
    }
    if (sum==s)
    {
        cout << "0";
    }
    else
    {
        if (n%2==0)
        {
            for (int i=0; i<=(n-1)/2; i++)
            {
                if (sum[i]!=s[i])
                {
                    cnt++;
                }
            }
        }
        else
        {
            for (int i=0; i<=(n-2)/2; i++)
            {
                if (sum[i]!=s[i])
                {
                    cnt++;
                }
            }
        }
    }
    cout << cnt;

    return 0;
}
