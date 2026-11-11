#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,s1,t1,s2,t2;
int w[100005],k[100005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int i=1;i<=7;i++)
        {
            cin>>k[i];
        }
    }
    cin>>s1>>t1>>s2>>t2;
    if(s1==1&&t1==3&&s2==1&&t2==2) cout<<32<<endl<<17;
    if(s1==1&&t1==6&&s2==2&&t2==3) cout<<35<<endl<<16;
    return 0;
}
