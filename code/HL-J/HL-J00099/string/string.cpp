#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<0;
    }
    else if(n==2)
    {
        for(int i=1;i<=n;i++)
        {
            int m1,m2;
            char c1,c2;
            cin>>m1>>c1;
            cin>>c1>>c2;
            if(c1!=c2)
            {
                cout<<min(m1,m2);
            }
        }
    }
    else if(n<=10)
    {
        string a;
        int cnt=0;
        for(int i=1;i<=10;i++)
        {
            int m;
            char c;
            cin>>m>>c;
            for(int j=1;j<=m;j++)
            {
                a+=c;
            }
        }
        int h=5;
        for(int i=5;i<=10;i++)
        {
            if(a[i]!=a[h])
            {
                cnt++;
            }
            h--;
        }
        cout<<cnt;
    }

    return 0;
}
