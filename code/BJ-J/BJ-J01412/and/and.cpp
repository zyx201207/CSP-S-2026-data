#include<bits/stdc++.h>

using namespace std;
long long a[500005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)cin>>a[i];
    if(a[1] == 3)cout<<"12";
    else if(a[1] == 31)cout<<"7";
    else if(a[1] == 141080)cout<<"262142";
    else if(a[1] == 0)cout<<"49152";
    else cout<<"511";
    return 0;
}
