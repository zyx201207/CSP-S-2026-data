#include<iostream>
using namespace std;
const int N=1e6+5;
int site[N];
int c,t,n,d,all=0,i,j,lin;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(i=1; i<=n; i++)
        {
            cin>>site[i];
        }
        for(i=3; i<=n;i++)
        {
            for(j=1;j <= i-2;j++)
            {
                if( (site[i] - site[j]) / d == 1 && (site[i] - site[j]) % d !=0) all++;
            }
        }
        cout<<all<<'\n';
        all=0;
    }
    return 0;
}
