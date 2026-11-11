#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",std);
    freopen("string.out","w",std);
    string s;
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        char y;
        cin >> x >> y;
        while(x--)
        {
            s+=y;
        }
    }
    long long cnt = 0;
    for(long long i = 0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i])
        {
            cnt++;
        }
    }
    cout << cnt;
}

