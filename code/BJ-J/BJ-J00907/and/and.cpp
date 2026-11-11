#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+9;
int a[maxn];
int n,m;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    bool f1=1,f2=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<a[n-m+1];
    cout<<endl;
    return 0;
}