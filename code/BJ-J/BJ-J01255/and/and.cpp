#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int x = 0,y=0;
struct node
{
    int v;
    int b;
};
node t[300005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> t[i].v;
        t[i].b = 1;
    }
    int id = 0,ll=0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(i == j)continue;
            y = max(t[i].v&t[j].v,y);//          ,
            if(t[i].v&t[j].v>=y)
            {
                ll = t[i].v;
                id = i;
            }
        }
    }
    t[id].b = 0;
    y = ll;
    for(int i = 2;i <= m;i++)
    {

        for(int j = 1;j <= n;j++)
        {
            if(t[j].b==0)continue;
            {
                if(y&t[j].v >= m) id = j;
                x = max(y&t[j].v,x);

            }

        }
        y = x;
        t[id].b = 0;

    }
    cout << y;
    return 0;
}
