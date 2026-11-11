#include<bits/stdc++.h>
using namespace std;
int n,m;
struct edg{
    int x,v;
}a[200010];
bool cmp1(edg x,edg y){
    if(x.x!=y.x) return x.x>y.x;
    return x.v>y.v;
}
bool cmp2(edg x,edg y){
    if(x.v!=y.v) return x.v>y.v;
    return x.x>y.x;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].x;
    for(int i=1;i<=n;i++){
        int s=a[i].x;
        while(s!=0){
            a[i].v+=s%2;
            s/=2;
        }
    }
    sort(a+1,a+n+1,cmp1);
    int ans1=a[1].x;
    for(int i=1;i<=m;i++){
        ans1&=a[i].x;
    }
    sort(a+1,a+n+1,cmp2);
    int ans2=a[1].x;
    for(int i=1;i<=m;i++){
        ans2&=a[i].x;
    }
    cout<<max(ans1,ans2);
    return 0;
}
