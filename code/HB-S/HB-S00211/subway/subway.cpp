#include<bits/stdc++.h>
using namespace std;
const int N = 55000;
int c,n,m,d,q,a[N];
struct node{
    int zhan[N],time[N],k;
}subway[500];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int k;cin>>subway[i].k;
        for(int j=1;j<=k;j++) cin>>subway[i].zhan[j]>>subway[i].time[j];
    }
    while(true){
        int s,e;cin>>s>>e;
        if(s==0 && e==0) return 0;
        int ans = a[s]+a[e];
        ans += subway[1].time[1]+subway[1].time[2];
        cout<<ans<<endl;
    }
    return 0;
}
