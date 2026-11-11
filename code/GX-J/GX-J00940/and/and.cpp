#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],ans=0,x=0,y=0;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[2];
    return 0;
}
