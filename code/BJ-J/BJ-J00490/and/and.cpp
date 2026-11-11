#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int x,cnt;
}a[200005];
int n,m;
bool cmp(node x,node y){
    if(x.cnt==y.cnt) return x.x>y.x;
    return x.cnt>y.cnt;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        int t=a[i].x;
        while(t){
            a[i].cnt+=(t%2);
            t/=2;
        }
    }
    sort(a+1,a+n+1,cmp);
    int ans=a[1].x;
    for(int i=2;i<=m;i++) ans&=a[i].x;
    cout<<ans;
    return 0;
}