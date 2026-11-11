#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,p,a;
    cin>>c>>n>>m>>d>>p;
    int w[1010010];
    for(int i=1;i<=m;i++)
        cin>>w[i];
        while(n--)
            cin>>a;
    while(c--)
    {
        int sum=0;
        for(int i=1;i<=m;i++)
            sum+=w[i];
        cout<<sum;
    }
    return 0;
}
