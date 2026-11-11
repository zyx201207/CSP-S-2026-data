#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmd(int q,int w){
    return q>w;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,sum;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmd);
    sum=a[1];
    for(int i=2;i<=m;i++)sum=sum&a[i];
    cout<<sum;

    cout<<'\n';
    return 0;
}
