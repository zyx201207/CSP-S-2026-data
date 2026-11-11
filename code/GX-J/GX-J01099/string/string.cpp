# include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin >> n;
    long long m;
    string z,ans;
    for (long long i = 1;i <= n;i++)
        {
            cin >> m;
            cin >> z;
            for (long long j = 1;j <= m;j++)
                {
                    ans += z;
                }
        }
    string re;
    for (long long i = ans.size();i >= 0;i--)
        {
            re += ans[i];
        }
    if (ans == re)
        {
            cout << "0";
            return 0;
        }
    else
        {
            string a,b;
            string bre;
            long long answer = 0;
            for (long long i = 0;i <= ans.size() / 2;i++)
                {
                    a += ans[i - 1];
                }
            for (long long i = ans.size();i > ans.size() / 2 + 1;i--)
                {
                    b += ans[i - 1];
                }
            for(long long j = b.size();j >= 0;j--)
                {
                    bre += b[j];
                }
            for (long long i = 0;i <= a.size();i++)
                {
                    if(a[i] != bre[i])
                        {
                            answer += 1;
                        }
                }
            cout << answer;
        }
    return 0;
}
/*
3
2 a
1 c
2 b
*/
