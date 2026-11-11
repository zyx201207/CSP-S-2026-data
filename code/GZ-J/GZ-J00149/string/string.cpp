//GZ-J00149 史君灵
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    string s1, s2, s3;
    cin >> n;
    long long chang = 0;
    int shu = 0;
    for(long long i = 1;i <= n;i++)
    {
        long long a;
        cin >> a >> s1[i];
        chang += a;
        for(long long j = 1;j <= a;j++)
        {
            shu++;
            s2[shu] = s1[i];
        }

    }
    long long cnt = 1,a1 = 0;
    for(long long i = chang;i >= 1;i--)
    {
        if(s2[i] != s2[cnt])
        {
            a1++;

        }
        cnt++;

    }
    if(a1 == 0)
        cout << 0;
    else
        cout << a1 / 2;
    return 0;
}
