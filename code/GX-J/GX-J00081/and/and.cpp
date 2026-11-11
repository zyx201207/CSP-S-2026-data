#include <bits/stdc++.h>
using namespace std;

const int maxn=2*1e5+5;
int a[maxn];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    cout<<a[1];
    return 0;
}
