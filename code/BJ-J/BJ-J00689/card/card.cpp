#include <bits/stdc++.h>
using namespace std;

int a[500010];
int cnt[500010];
int num[500010];
int n, m;

bool check()
{
    for (int i = 1; i <n; i++)
    {
        if(!(a[i] <= a[i + 1]))
        {
            //cout << a[i] << " " << a[i + 1] << endl;
            return false;
        }
    }
    return true;
}

int main()
{

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >>n >>m;
    for (int i = 1; i <= n; i++)
    {
        cin >>a[i];
    }
    if (check())
    {
        //cout << 114514;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != a[i + 1])
            {
                cout << i << " ";
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            string paidui = "";
            for (int j = i; j <= n; j++)
            {
                int nowin = a[j];
                int cur = paidui.find(nowin + '0');
                if (cur == string::npos)
                {
                    paidui = paidui + char(nowin + '0');
                }
                else
                {
                    paidui = paidui.substr(0, cur);
                    paidui = paidui + char(nowin + '0');
                }
                //cout << paidui << " ";
            }
            //cout << endl;
            for (int j = 1; j <= m; j++)
            {
                int cur = paidui.find(j + '0');
                if (cur != string::npos)
                {
                    cnt[j]++;
                }
            }
        }
        for (int i = 1; i <= m; i++)
        {
            cout << cnt[i] << " ";
        }
    }
    return 0;
}
