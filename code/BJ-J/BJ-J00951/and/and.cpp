#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int bi(long long a,long long b)
{
    return a & b;
}
int an(int y,int ma)
{
    if(y==m+1)
    {
        return ma;
    }
    for(long long i=y;i<=n;i++)
    {
        if(y==1)
        {
            ma=a[i];
        }
        ma=max(ma,an(y+1,bi(ma,a[i])));
    }
    return ma;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<an(1,a[1]);
    return 0;
}
