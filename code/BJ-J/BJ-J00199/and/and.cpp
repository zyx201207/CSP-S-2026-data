#include<bits/stdc++.h>
using namespace std;
int n,m,maxn,a[10000001];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]&a[j]>maxn)
                maxn=a[i]&a[j];
    cout<<maxn;
}