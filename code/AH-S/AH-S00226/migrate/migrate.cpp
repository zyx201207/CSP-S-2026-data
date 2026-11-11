#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
long long c,n,m,d,p,w[2000005],t,a[505][20005],k[505],tu[505][505],l[100005],r[100005],cnt;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>w[i];
        cout<<n<<endl;
    }
    return 0;
}

