#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],cnt,c[300005];
bool f[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        cnt = 0;
        for(int j = 1; j <= m; j++) f[j] = 1;
        for(int j = 1; j <= n - i + 1; j++)
        {
            if(f[a[j]])
            {
                f[a[j]] = 0;
                b[++cnt] = a[j];
            }
            else
            {
                for(int k = 1; k <= j; k++)
                {
                    if(b[k] == a[j])
                    {
                        for(int l = k; l < j; l++)
                        {
                            b[l] = 0;
                            f[b[l]] = 1;
                        }
                    }
                }
            }
            for(int j = 1; j <= cnt; j++)
            {
                if(!f[a[j]]) c[j]++;
            }
        }
    }
    for(int i = 1; i <= m; i++) cout << c[i];
    return 0;
}//saasaasasassassssssasaasasdadssssdasssssssssssssssssssssadddddddddddddddddddddddaaaaaaaaaaaaaaaassssssssssssssaaaaaaaaaasssssssddddddddddwaaadafqfawfawdawdadas
