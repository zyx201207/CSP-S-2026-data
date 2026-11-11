#include <bits/stdc++.h>
using namespace std;

int n,m,a,b,h1,h2;
string x,y;
int ans[5]={};

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>x>>m>>y;
    a=x[0]*10+x[1]*10;
    b=y[0]*10+y[1]*10;
    h1=x[2]-'A'+1;
    h2=y[2]-'A'+1;
    if(n==m)
        ans[1]=1;
    if(a==b&&ans[1]==1)
        ans[2]=1;
    if(h1<=3)
        if(h2<=3&&ans[2]==1)
            ans[3]=1;
    if(h1>3)
        if(h2>3&&ans[2]==1)
            ans[3]=1;
    if(ans[3]==1&&abs(h1-h2)==1)
        ans[4]=1;
    for(int i=1;i<=4;i++)
        cout<<ans[i];
    return 0;
}
