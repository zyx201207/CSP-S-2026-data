#include<bits/stdc++.h>
using namespace std;
const int N=200010;
long long n,m,a[N],s=1;
int main()
{
    //freopen("and.in", "r", stdin);
    //freopen("and.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    s=a[n];
    for(int i=n-1;i>n-m;i--)
        s&=a[i];
    cout<<s;
    return 0;
}

