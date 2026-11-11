#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,ans=-114514;
int a[N];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n,cmp);
    if((a[m-1]&a[0])==0) cout<<a[m-1]<<"\n";
    else cout<<(a[m-1]&a[0])<<"\n";
    return 0;
}