#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w", stdout);
    long long n, m;
    long long a[500010] = {}, ans[500010] = {};

    cin >> n >> m;
    for(long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(long long i = 1; i <= n; i++)
    {
        string s, s2;
        int len = 0;
        for(long long j = i; j <= n; j++)
        {
            int i = 0;
            while(s[i] != (char)a[j] + '0' && i < len)
            {
                s2 += s[i];
                i++;
            }
            s2 += (char)a[j] + '0';
            //cout << s2 << endl;
            s = s2;
            s2 = "";
            //cout << s << endl;
            len = s.length();
        }
        for(int k = 0; k < len; k++)
        {
            ans[int(s[k] - '0')]++;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        cout << ans[i] << ' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

