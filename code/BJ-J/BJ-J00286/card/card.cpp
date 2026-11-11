#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],c[300005];
int main()
{
    freopen("card.in","r","stdin");
    freopen("card.out","w","stdout");
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        memset(b,0,sizeof(b));
        for(int j = i;j <= n;j++)
        {
            if(b[a[j]]==1)
            {
                for(int k = j-1;k >= 1;k--)
                {
                    b[a[k]]=0;
                    if(a[k]==a[j])
                    {
                        break;
                    }
                }
            }
            b[a[j]]++;
        }
        for(int j = 1;j <= m;j++)
        {
            c[j]+=b[j];
        }
    }
    for(int i = 1;i <= m;i++)
    {
        cout<<c[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
