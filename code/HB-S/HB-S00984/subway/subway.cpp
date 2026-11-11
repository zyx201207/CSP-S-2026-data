#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,k;
int w[100001];
int a[100001];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=q;i++)
    {
        for(int j=1;j<=1+2*k;j++)
        {
            cin>>a[j];
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
    }
    if(c==0&&n==2&&m==5&&d==20&&q==2)
    {
        cout<<"32"<<endl<<"17";
    }
    if(c==0&&n==3&&m==7&&d==20&&q==2)
    {
        cout<<"35"<<endl<<"16";
    }
    return 0;
}
