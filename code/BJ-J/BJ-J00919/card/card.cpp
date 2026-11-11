#include <bits/stdc++.h>
using namespace std;

//Remember long long;
//freopen() 召唤成功
int arr[500010];
int ans[500010];
int now[300010];
int main()
{
  freopen("card.in", "r", stdin);
  freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        cin >> arr[i];
    }
    int szfnow = 1;
    for(int k = 1; k <= n; k ++)
    {
        for(int i = 1; i <= n; i ++) now[i] = 0;
        for(int i = k; i <= n; i ++)
        {
            bool find = 0;
            for(int j = 1; j <= szfnow; j ++)
            {
                if(now[j] == arr[i])
                {
                    int delnum = 0;
                    for(int l = j; l <= szfnow; l ++)
                    {
                        now[l] = 0;
                        delnum ++;
                    }
                    szfnow -= delnum;

                }
            }
            now[szfnow + 1] = i; szfnow ++;
        }
        for(int i = 1; i <= szfnow; i ++) ans[now[i]] ++;
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}
/*
喜欢在机房像区一样爬行的传奇回忆漩涡Whx同学
在Blxod.io方块战争中被RPG单杀114514次的Wbk同学
英语阅读A篇写反的信息大佬，LWC同学
传奇闪避王WJT同学，竞赛课课上无数次打游戏，从未被发现，却在校内信息课上因玩切水果被老师制裁.
如果你们看到了这行字
说明




我饿了
赶紧V我50吃KFC
*/
