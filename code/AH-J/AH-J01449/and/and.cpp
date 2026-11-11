#include<bits/stdc++.h>
using namespace std;
struct y
{
    long long a;
    bool g;
    string c;
}s[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long f = 0;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        cin>>s[i].a;
        s[i].g = 1;
        f = max(f,s[i].a);
    }
    if(m == 1)
    {
        cout<<f;
        return 0;
    }
    f = 0;
    for(int i = 1;i < m;i++)
    {
        if(i == 1)
        {
            int x = 0,z = 0;
            for(int j = 1;j < n;j++)
            {
                for(int r = j+1;r <= n;r++)
                {
                    if(s[j].a & s[r].a > f)
                    {
                        s[x].g = 1;
                        s[z].g = 1;
                        s[j].g = 0;
                        s[r].g = 0;
                        x = j;
                        z = r;
                        f = s[j].a & s[r].a;
                    }
                }
            }
        }
        else
        {
            int z = 0;
            for(int j = 1;j <= n;j++)
            {
                if(s[j].g == 0)
                    continue;
                if(f & s[z].a < f & s[j].a)
                {
                    s[z].g = 1;
                    z = j;
                    s[j].g = 0;
                }
            }
            f = f & s[z].a;
        }
    }
    cout<<f;

    return 0;
}
