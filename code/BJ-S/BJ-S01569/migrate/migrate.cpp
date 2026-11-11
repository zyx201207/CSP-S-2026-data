#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int n;
ll d,a[2000001],sub[2000001];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ID,T;
    cin>>ID>>T;
    while(T--)
    {
        cin>>n>>d;
        a[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sub[i]=a[i]-a[i-1];
        }
        sub[1]=0;
        if(d<2*sub[2] || d>=3*sub[2])
        {
            cout<<0<<"\n";
            continue;
        }
        cout<<n-3<<"\n";
    }
    return 0;
}