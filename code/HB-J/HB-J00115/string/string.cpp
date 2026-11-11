#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    long long n;
    long long cnt=0;
    cin >> n;
    long long num[n+5];
    string s[n+5],source="";
    for(int i=0;i<n;i++)
    {
        cin >> num[i] >> s[i];
        for(int j=0;j<num[i];j++)
        {
            source += s[i];
        }
    }


    for(int i=0;i<(source.size()/2);i++)
    {
        if(source[i]!=source[source.size()-i-1])
        {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}
