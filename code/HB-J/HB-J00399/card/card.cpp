#include <bits/stdc++.h>
using namespace std;

int n,m,num,a[500005],cnt2[300005],ans[300005];
bool f = 1,cnt[300005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        cnt2[a[i]]++;
        if(a[i] < a[i-1])
            f = 0;
    }
    if(f)
    {
        for(int i = 1;i <= m;i++)
        {
            if(cnt2[i] > 1)
                num += cnt2[i]-1;
            cout << i+num << " ";
        }
    }
    else
    {
        for(int i = 1;i <= n;i++)
        {
            memset(cnt,0,sizeof(cnt));
            for(int j = i;j <= n;j++)
            {
                bool flag = 0;
                for(int k = i;k < j;k++)
                {
                    if((a[k]==a[j]) && (cnt[a[k]]==1))
                        flag = 1;
                    if(flag)
                        cnt[a[k]] = 0;
                }
                cnt[a[j]] = 1;
            }
            for(int j = 1;j <= m;j++)
                if(cnt[j] == 1)
                    ans[j]++;
        }
        for(int i = 1;i <= m;i++)
            cout << ans[i] << " ";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
