#include <bits/stdc++.h>
using namespace std;

int n, len;
string a;

string hw(string t)
{
    string f;
    for(int i=t.size()-1; i>=0; i--)
    {
        f+=t[i];
    }
    return f;
}

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for(int i=1; i<=n; i++)
    {
        int num;
        char d;
        cin >> num >> d;
        len+=num;
        for(int j=1; j<=num; j++)
        {
            a+=d;
        }
    }
    if(a==hw(a))
    {
        cout << 0;
        return 0;
    }
    int r=len-1, cnt=0;
    for(int i=0; i<=len/2-1; i++)
    {
        if(a[r]!=a[i])
        {
            a[r]=a[i];
            cnt++;
        }
        if(a==hw(a))
        {
            cout << cnt;
            return 0;
        }
        r--;
    }

    return 0;
}
