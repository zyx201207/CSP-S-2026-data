#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL pos_begin[200005];
LL pos_end[200005];
char alp[200005];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    LL n;
    LL cnt = 0, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        LL num;
        char c;
        cin >> num >> c;
        pos_begin[i] = cnt + 1;
        pos_end[i] = cnt + num;
        alp[i] = c;
        cnt += num;
    }
    LL pos, L = pos_end[n];
    int i = 1, j = n;
    while(1)
    {
        LL p = pos_begin[i], q = pos_end[i];
        if(p > L / 2) break;
        if(q > L / 2)
        {
            q = L / 2;
        }
        LL jp = L - q + 1;
        LL jq = L - p + 1;
        while(jq >= jp)
        {
            if(alp[j] == alp[i])
            {
                jq = pos_begin[j] - 1;
                if(jp < pos_begin[j]) j--;
                continue;
            }
            else ans += (jq - max(pos_begin[j], jp) + 1);
            jq = pos_begin[j] - 1;
            if(jp < pos_begin[j]) j--;
        }
        i++;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
