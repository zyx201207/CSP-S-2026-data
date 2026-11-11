#include <bits/stdc++.h>
using namespace std;
int calc(int n){
    int cnt=0;
    while(n){
        int t=log2(n);
        n-=(1<<t);
        cnt++;
    }
    return cnt;
}
struct node{
    int a,c;
};
bool cmp(node x,node y){
    if(x.c==y.c){
        return x.a>y.a;
    }
    return x.c>y.c;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    node a[n+10]={};
    for(int i=1;i<=n;++i){
        cin>>a[i].a;
        a[i].c=calc(a[i].a);
    }
    sort(a+1,a+n+1,cmp);
    int ans=a[1].a;
    for(int i=1;i<=m;++i){
        ans&=a[i].a;
    }
    cout<<ans<<endl;
    return 0;
}