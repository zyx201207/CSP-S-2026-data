#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin >> n;
    string s = "";
    int a;
    char c;
    for(long long i = 1;i<=n;i++)
    {
        cin >> a >> c;
        for(int j = 1;j<=a;j++)
        {
            s+=c;
        }
    }
    long long sum = 0;
    long long cnt = s.length();
    for(long long i = 0;i<s.length();i++)
    {
        cnt--;
        if(cnt == i)
        {
            break;
        }
        if(s[i]!=s[cnt])
        {
            sum++;
        }
    }
    cout << sum;
    return 0;
}
