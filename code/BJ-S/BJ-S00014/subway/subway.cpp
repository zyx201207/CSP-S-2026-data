#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500010],k[500010];
struct node{
    long long s,t;
}a[500][500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++)cin>>a[i][j].s>>a[i][j].t;
    }
    while(q--){
        long long st,ed,cnt=0;cin>>st>>ed;
        cnt=cnt+w[st];
    cnt=cnt+w[ed];
    cout<<cnt<<"\n";
    }
    
    return 0;
}