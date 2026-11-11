#include<bits/stdc++.h>
using namespace std;
long long k1=0,head[500009],w[5000009],a[500009],v[1000009];
struct line{
    int to,pre;
};
line b[500009];
void add(int x,int y){
    k1++;b[k1].to=y;b[k1].pre=head[x];head[x]=k1;
}
long long jist(int x,int y){

}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int n,m,d,c,q,t,k,ans=0;cin>>c>>t;
    for(int i1=1;i1<=t;i1++){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            cin>>w[i]>>v[i];
            add(w[i],v[i]);add(v[i],w[i]);
        }
    }

    return 0;
}
