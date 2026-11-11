//王隽唯 北京师范大学贵阳附属中学 准考证号GZ-S00441 座位号22 
#include <bits/stdc++.h>
using namespace std;

int main()
{

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);


    int n,m,ans,anst;
    ans = 0;
    anst = 0;
    cin >> n >> m;
    int c[n];
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(c[j]<c[j+1])
            {
                int t = c[j];
                c[j]=c[j+1];
                c[j+1]=t;
            }
        }
    }

    int mininum = 2147483647;
    for(int i = n; i >= 0; i--)
    {
        if(c[i]<mininum)
        {
            mininum = c[i];
        }
    }

    if(mininum<0)
    {
        mininum*=-1;
        for(int i = 0; i < n; i++)
        {
            c[i]+=mininum;
        }

    }

    while(m)
    {
        for(int i = n-1; i >= 0; i--)
        {
            if(c[i]==c[n-1])
            {
                if(m==0)
                {
                    break;
                }
                m--;
                c[i]++;
            }

            for(int i = n-1; i >= 0; i--)
            {
                if(c[i]==c[n-1])
                {
                    ans++;
                }
            }

            if(ans > anst)
            {
                anst = ans;
            }
            ans = 0;
        }
    }

    cout << anst;
}
