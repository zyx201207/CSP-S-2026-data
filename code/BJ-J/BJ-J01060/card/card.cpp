#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[500010];
/*int cnt;
int summ;
int t[300010];
bool ttt[300010];
int tt[300010];*/
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    /*int akf = n;
    while(akf --)
    {   cnt ++;
        for(int i = 1; i <= n; i ++) {ttt[i] = false; t[i] = 0;}
        bool flag = false;
        for(int i = cnt; i <= n; i ++)
        {
            if(ttt[a[i]] == false) {ttt[a[i]] = true; t[a[i]] ++;}
            else{
            for(int j = cnt; j <= i; j ++)
            {
                if(a[i] == a[j])
                {
                    for(int k = j; k <= n; k ++)
                    {

                        if(t[a[k]] > 0)
                            t[a[k]] --;

                    }break;

                }
            }
            }
        }
        for(int i = cnt; i <= n; i ++)
        {
            if(t[a[i]] > 0) tt[a[i]] ++;
        }
    }
    for(int i = 1; i <= m; i ++)
    {
        cout << tt[a[i]]<< " ";
    }*/
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = n; i >= 1; i --)
{
        cout << i << " ";
}
    return 0;
}
