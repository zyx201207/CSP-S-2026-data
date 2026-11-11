#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main()
{
    freopen("subway.in","r","stdin");
    freopen("subway.out","w","stdout");
    int c,n,m,d,q,num;
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= m;i++)
    {
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin>>x;
        for(int j = 1;j <= 2*x;j++)
        {
            int y;
            cin>>y;
            if(j==2)
            {
                num=y;
            }
        }
    }
    for(int i = 1;i <= q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<a[x]+a[y]+(y-x)*2*num<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
