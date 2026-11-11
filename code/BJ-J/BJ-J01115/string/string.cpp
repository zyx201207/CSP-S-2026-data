#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w", stdout);
    long long n, ans = 0;
    string s;

    cin >> n;
    for(long long i = 1; i <= n; i++)
    {
        long long num;
        char a;
        cin >> num >> a;
        for(long long j = 1; j <= num; j++)
        {
            s += a;
        }
    }

    int len = s.length();
    for(long long i = 0; i <= len / 2 - 1; i++)
    {
        if(s[i] != s[len - i - 1])
        {
            ans++;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
