#include<iostream>
#include<algorithm>
using namespace std;
int a[200010], n,m,ans=0;
bool b[200010];
void f(int x,int y,int z)
{
    if(y==0){
        ans=max(ans,z);
        return;
    }
    for(int i = x+1; i <= n-y+1; i++)
    {
        f(i,y-1, z&a[i]);
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n-m+1; i++)
    {
        f(i,m-1,a[i]);
    }
    cout << ans;
    return 0;
}
