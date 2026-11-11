#include<iostream>
#include<vector>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int res=0;
    for(int i=30;i>=0;i--)
    {
        int test=(res|(1<<i));
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if((a[j]&test)==test)
            {
                cnt++;
            }
        }
        if(cnt>=m) res=test;
    }
    cout<<res;
}
