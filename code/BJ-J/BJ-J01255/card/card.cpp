#include <bits/stdc++.h>
using namespace std;
int aa[500005];
char a[500005];
string s;
queue<int> q;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        s += a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        for(int m = 1;m <= n;m++)
        {
            char ss = a[m];
            int w = s.find(ss);
            if(w != -1)
            {
                string sss = "";
                for(int m = 1;m <= w;m++)
                {
                    sss += s[m];
                }
                s = sss;
            }
        }
        int k = s.size();
        for(int j = 0;j < k;j++)
        {
            a[s[j]-'0']++;

        }
    }
    for(int i = 1;i <= m;i++)
    {

        cout << aa[i];
    }
    return 0;
}
