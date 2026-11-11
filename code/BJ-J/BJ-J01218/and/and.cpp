#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int n,m;//2e5
struct w{
    int shu;
    int zhi;
}k[200005];
void ch(long long x,int i){
    k[i].shu = x & (x-1);
    k[i].zhi = x | 0;
}
int cmp(w x,w y){
    if(x.shu != y.shu){
        return x.shu > y.shu;
    }else{
        return x.zhi > y.zhi;
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        ch(a[i],i);
    }
    sort(k + 1,k + n + 1,cmp);
    int s = 1e9;
    for(int i = 1;i <= m;i++){
        s = min(s,k[i].zhi);
    }
    cout<<s;
    return 0;
}