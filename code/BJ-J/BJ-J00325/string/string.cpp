#include<bits/stdc++.h>
using namespace std;

long long cishu(string s , string t)
{
    long long cnt = 0;
    int len = s.size();
    for (int i = 0; i <= len - 1; i++)
        if (s[i] != t[i]) cnt++;
    return cnt;
}

int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    string s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        long long a;
        cin >> a >> ch;
        for (int j = 1; j <= a; j++) s += ch;
    }
    long long len = s.size();
    long long h = (len + 1) / 2;
    string s1 , s2;
    s1 = s.substr(0 , h);
    long long minn = 1e17;
    string t;
    if (len % 2 == 0)
    {
        s2 = s.substr(h);
        string t1 , t2;
        int len1 = s1.size() , len2 = s2.size();
        for (int i = len1 - 1; i >= 0; i--)
            t1 += s1[i];
        for (int i = len2 - 1; i >= 0; i--)
            t2 += s2[i];
        t = s1 + t1;
        minn = min(minn , cishu(s , t));
        t = t1 + s1;
        minn = min(minn , cishu(s , t));
        t = s2 + t2;
        minn = min(minn , cishu(s , t));
        t = t2 + s2;
        minn = min(minn , cishu(s , t));
    }
    else
    {
        s2 = s.substr(h - 1);
        string t3 , t4;
        long long len3 = s1.size() , len4 = s2.size();
        for (int i = len3 - 2; i >= 0; i--)
            t3 += s1[i];
        for (int i = len4 - 2; i >= 0; i--)
            t4 += s2[i];
        t = s1 + t3;
        minn = min(minn , cishu(s , t));
        t = s2 + t4;
        minn = min(minn , cishu(s , t));
    }
    cout << minn << endl;
    return 0;
}
