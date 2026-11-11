#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n,a[50010],b[50010],c[50010],l=0,sum=0,cnt=0;
    cin >> m >> n;
    for(int i=1;i<=m;i++)
    {
        cin >> a[i];
        cnt++;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=cnt-i;j++)
        {
            b[j]=a[j+i];
        }
        for(int j=2;j<=cnt-i-sum;j++)
        {
            for(int k=1;k<j;k++)
            {
                if(b[j]==b[k])
                {
                    l=0;
                    while(l<=j)
                    {
                        b[l]=b[j+l];
                        l++;
                        j=2;
                        k=1;
                    }
                    sum=sum+l;
                }
            }
        }
        for(int j=1;j<=cnt-sum-i;j++)
        {
            c[b[j]]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << c[i] << " ";
    }
    return 0;
}
