#include <bits/stdc++.h>
using namespace std;
int m,n;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    int a[n+4]={0};
    for(int i=1;i<=n;i++)
    {

        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if(m==1)
    {

        cout << a[n];
    }
    else if(m==2)
    {
        int maxn=-1;
        int s[n+3][n+3]={0};
        for(int i=1;i<=n;i++)
        {
            s[i][0]=a[i];
            for(int j=1;j<=n-1;j++)
            {
                if(i==j)
                {
                    j++;
                }
                s[0][j]=a[j];
                s[i][j]=s[i][0]&s[0][j];
                if(s[i][j]>=maxn)
                {

                    maxn=s[i][j];
                }
            }
        }
        cout << maxn;
    }
    else
    {
        int abc=a[1];
        for(int i=2;i<=n;i++)
        {

            abc=abc&a[i];
        }
        cout << abc;
    }




    return 0;


}

