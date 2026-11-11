#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],c[100000];
int main()
{
    freopen("crystal.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int d=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    d=a[2]-a[1];
    int b=m;
    int cnt=1;
    for(int i=1;i<=m;i++)
    {
        b=b-i*d;
        if(b<0)
        {
            break;
        }
        cnt++;
    }
    cout<<cnt;
    freopen("crystal.out","w",stdout);
    return 0;
}

