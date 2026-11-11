#include<bits/stdc++.h>//kale
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,b,c=0;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=1;i<=n;i++)
    {
        b+=a[i];
        if(a[i]*i<=b+m)
            c++;
    }
    cout<<c;
    return 0;
}
