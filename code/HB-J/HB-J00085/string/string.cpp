#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s="";
    for(int i = 1;i <= n;i++)
    {
        int x;
        char c;
        cin >> x >> c;
        for(int j = 1;j <= x;j ++)
        {
            s += c;
        }

    }
    long long sum = s.size(),cnt = 0;
    string a,b;
    if (sum % 2 == 0) a = s.substr(0,sum/2),b = s.substr(sum/2,sum);
    else a = s.substr(0,sum/2),b = s.substr(sum/2+1,sum);
    reverse(a.begin(),a.end());
    for(int i = 0;i < a.size();i++)
    {

        if (a[i] != b[i]) cnt ++;
    }
    cout << cnt;

    return 0;
}
