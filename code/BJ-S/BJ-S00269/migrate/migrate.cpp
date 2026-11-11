#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2000005];
int main()
{
    freopen("migrate.in","r","stdin");
    freopen("migrate.out","w","stdout");
    int c,t;
    cin>>c>>t;
    for(int i = 1;i <= t;i++)
    {
        int x,y;
        cin>>x>>y;
        for(int j = 1;j <= x;j++)
        {
            cin>>a[j];
        }
        cout<<(a[x]-a[1])/y<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
