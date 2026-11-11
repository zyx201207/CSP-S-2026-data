#include <bits/stdc++.h>
using namespace std;
int a[10000010];
bool px(int c,int d){
    return c>d;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,sum;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,px);
    sum=a[1];
    for(int i=2;i<=m;i++)
    {
        sum=sum&a[i];
    }
    cout<<sum;
    return 0;
}
