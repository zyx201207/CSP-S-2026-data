#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int a;
    string s,b;
    for(int i = 1; i <= n;i++)
    {
        cin >> a;
        cin >>  b;
        for(int j = 1;j <= a;j ++) s = s+b;

    }
    long long m = s.size()-1;
    long long ans = 0;
    for(int i = 0; i<= ((s.size() +1 )/ 2);i++)
    {
        if(s[i] != s[m]) {
                ans++;
                s[m] = s[i];
        }
        m--;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
