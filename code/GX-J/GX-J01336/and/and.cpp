#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
//    for(int i=1;i<=n;i++)
//    {
//        cout<<a[i]<<" ";
//    }
//    cout<<endl;
    int sum=a[n];
    for(int i=n-1;i>n-m;i--)
    {
        sum=sum&a[i];
    cout<<sum<<endl;
    }
    return 0;
}
//4
//2 a
//2 b
//3 c
//2 d
