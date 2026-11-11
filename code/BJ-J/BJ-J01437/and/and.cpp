#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,cmp);
    int x=a[1];
    for(int i=2;i<=m;i++)
    {
        x=(a[i]&x);
    }
    cout<<x<<endl;
    return 0;
}
