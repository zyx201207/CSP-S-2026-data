// T1应该是45？
// 这次考试可能我也只能打45了…… 
// 算了没关系……上次打20…… 
// 突然有点想上电视…… 
// #include <bits/stdc++.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int n,m,a[5010],s[5010][5010];
int ans;
int main()
{
    freopen("crystal3.in","r",stdin);
    freopen("crystal.out","w",stdout);

    // cin >> n >> m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;++i)
    {
        // cin >> a[i];
        scanf("%d",&a[i]);
    }

    sort(a+1,a + n + 1);

    for(int i = 1;i<=n;++i)
    {
        for(int j = i + 1;j<=n;++j)
        {
            // cout << a[j] << ' ' << a[i] << endl;
            s[i][j] = a[j] - a[i];
        }
    }

    // for(int i = 1;i<=n;++i)
    // {
    //     for(int j = 1;j<=n;++j)
    //     {
    //         cout << s[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = n;i>=2;--i)
    {
        int t = 0,num = 0;
        bool f = 1;
        for(int j = i;j>=2;--j)
        {
            if(f)
            {
                if(num + s[j-1][i] <= m)
                {
                    ++t;
                    num += s[j-1][i];
                    // printf("(%d,%d): %d\n",j-1,i,s[j-1][i]);
                }
                else
                {
                    f = 0;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        ans = max(ans,t);
        // printf("t: %d\n",t);
        // printf("ans: %d\n\n",ans);
    }

    // cout << max(1, ans + 1);
    printf("%d",max(1, ans + 1));

    fclose(stdin);
    fclose(stdout);
    return 0;
}
