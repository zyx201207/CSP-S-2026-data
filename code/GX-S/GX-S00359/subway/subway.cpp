#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,cnt=0;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++)
    {
        cnt++;
    }
    cout<<cnt;
    return 0;
}
