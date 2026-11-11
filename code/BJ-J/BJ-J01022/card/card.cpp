#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int mn[500010];
int b[300010];
int len = 0;
int check(int x)
{
    for(int k = 1;k<= len;k++)
    {
        if(mn[k] == x)
        {
            return k;
        }
    }
    return -1;
}

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        len = 0;
        memset(mn,0,sizeof(mn));
        for(int j = i;j <= n;j++)
        {

            int t = check(a[j]);
            if(t == -1)
            {

                len ++;
                mn[len] = a[j];
                //cout << mn[len] << "a" << len << "jieshu";
            }
            else
            {
                len = t;
                mn[len] =  a[j];
                //cout << mn[len] << "b" << len << "jieshu";
            }

        }
        for(int j = 1;j <= len;j++)
        {
            //cout << mn[j] << " ";
            b[mn[j]]++;
        }
        //cout << endl;
    }
    for(int i = 1;i <= m;i++)
    {
        cout << b[i] << " ";
    }
    return 0;
}