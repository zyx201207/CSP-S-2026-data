#include <iostream>
#include <cstdio>
using namespace std;
int desktop[300005] = {}, cnt = 0;
int pd[500005] = {};
int num[500005] = {};

int main()
{
    FILE* read_file = freopen("card.in", "r", stdin);
	FILE* write_file = freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> pd[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            bool flag = false;
            //now:pd[j]
            //check out:desktop[1] ~ desktop[cnt] have pd[j]?cnt = i
            for(int k = 1; k <= cnt; k++)
            {
                if(pd[j] == desktop[k])
                {
                    cnt = k;
                    flag = true;
                    desktop[k] = pd[j];
                    break;
                }
            }
            if(!flag)
            {
                desktop[++cnt] = pd[j];
            }
        }
        for(int j = 1; j <= cnt; j++)
        {
            num[desktop[j]]++;
            desktop[j] = 0;
        }
        cnt = 0;
    }
    for(int i = 1; i <= m; i++)
    {
        cout << num[i] << ' ';
    }
}