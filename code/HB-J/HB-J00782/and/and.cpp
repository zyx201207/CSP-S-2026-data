#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+7;
int n,m;
struct node{
    int num;
    int c[35];
}a[N];
inline void pd(node nn){
    int x=nn.num;
    int cnt=1;
    while(x!=0){
        cnt++;
        if(x%2==1)nn.c[cnt]++;
        x/=2;
        nn.c[0]=cnt;
    }
}
bool cmp1(node x,node y){
    int maxl=max(x.c[0],y.c[0]);
    for(int i=1;i<=maxl;i++){
        return x.c[i]>y.c[i];
    }
    return x.num>y.num;
}
int ans;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
        pd(a[i]);
    }
    sort(a+1,a+1+n,cmp1);
    ans=a[1].num;
    for(int i=2;i<=m;i++){
        ans&=a[i].num;
    }
    cout<<ans;
    return 0;
}