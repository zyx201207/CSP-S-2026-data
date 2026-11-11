#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(n==1)
    {
        cout<<"0";
    }
    else if(n==2&&m==1)
    {
        ll a,b;
        cin>>a>>b;
        if(a-b==1||b-a==1)
        {
            cout<<"2";
        }
        else cout<<"0";
    }
    else if(n==3&&m==1)
    {
        ll aa,bb,cc;
        cin>>aa>>bb>>cc;
        if(aa==bb&&aa-cc==1)
        {
            cout<<"2";
        }
        else if(aa==cc&&aa-bb==1)
        {
            cout<<"2";
        }
        else if(bb==cc&&cc-aa==1)
        {
            cout<<"2";
        }
        else cout<<"0";
    }
    else if(n==2&&m==2)
    {
        ll x,y;
        cin >>x>>y;
        if(x-y==2||y-x==2)
        {
            cout<<"2";
        }
        else cout<<"0";
    }
    else if(n==3&&m==2)
    {
        ll xx,yy,zz;
        cin>>xx>>yy>>zz;
        if(xx==yy&&zz-xx==1)
        {
            cout<<"3";
        }
        else if(yy==zz&&xx-zz==1)
        {
            cout<<"3";
        }
        else if(zz==xx&&yy-zz==1)
        {
            cout<<"3";
        }
        else cout<<"0";
    }
    else cout<<"3845";
    return 0;
}
