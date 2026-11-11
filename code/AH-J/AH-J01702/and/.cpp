#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[200011],m,n;
bool cmp(int a,int b)
{
    return a>b;
};
int main()
{
    freopen("and3.in","r",stdin);
    freopen("and3.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    cout<<a[m];
    return 0;
}

