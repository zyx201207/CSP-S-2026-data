#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

bool mycmp(long long x,long long y)
{
    if(x>y)
    {
        return true;
    }
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    long long a[200005];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,mycmp);
    long long s=a[0];
    for(int i=1;i<=m;i++)
    {
        s=s&a[i];
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
