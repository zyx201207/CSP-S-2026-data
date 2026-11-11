#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b;
}a[200005];
int f(int n){
    int ans=0;
    while(n){
        ans+=n%2;
        n/=2;
    }
    return ans;
}
bool cmp(node a,node b){
    if(a.b!=b.b){
        return a.b>b.b;
    }
    return a.a>b.a;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].a;
        a[i].b=f(a[i].a);
    }
    sort(a+1,a+n+1,cmp);
    int ans=a[1].a;
    for(int i=1;i<=m;i++){
        ans&=a[i].a;
    }
    cout<<ans;
    return 0;
}
