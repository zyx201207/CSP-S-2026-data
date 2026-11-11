#include<bits/stdc++.h>
using namespace std;
const int N=5e5+2;
int c,n,m,d,p;
int w[N];
int k[N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++) cin>>w[i];
    long long cnt=0;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int i=1;i<=k;i++)
        {
            long long a;
            cin>>a;
            cnt+=a;
        }
    }
   for(int i=1;i<=p;i++)
   {
       cout<<cnt<<endl;
   }
   return 0;
}
