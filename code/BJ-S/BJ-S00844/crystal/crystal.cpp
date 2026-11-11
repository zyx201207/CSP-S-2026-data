#include <bits/stdc++.h>
using namespace std;
//Remember long long
long long n, m;
long long arr[500010];
const long long N = 200010;
long long stru[N];
int main()
{
  freopen("crystal.in", "r", stdin);
  freopen("crystal.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(long long i = 1; i <= n; i ++)
    {
        cin >> arr[i];
        stru[arr[i] + 100001] ++;
    }
    long long ans = 0, glm = 0;
    long long fewer = m;
    for(long long i = 1; i <= 200001; i ++)
    {
        if(stru[i] != 0)
        {
            glm = stru[i], fewer = m;
            for(long long j = i - 1; j >= 1; j --)
            {
                if(stru[i] != 0 && fewer >= (i - j))
                {
                    glm += min(stru[j], fewer / (i - j));
                    fewer -= min(stru[j], fewer / (i - j)) * (i - j);
                }
                if(fewer < (i - j)) break;
            }
            ans = max(ans, glm);
        }

    }
    cout << ans;
    return 0;
}
/*
潮起潮落 3K
删除所有代码，将等同于删除数量+1的题目代码加入Code Blocks
其中每有一题通过不少于3个测试点，额外获得10分

一触即溃 9K
将所有题目转换为P1001 A+B Problem

战略重心 7K
抉择：删除所有最短路题目 或 删除所有线段树题目

前线与家乡 4K
使T1与T3的难度变为 普及-

*/
