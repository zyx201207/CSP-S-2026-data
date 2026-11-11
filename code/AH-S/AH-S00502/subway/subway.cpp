#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    int a,t;
};
int c,n,m,d,q,y;
int w[500100];
vector<node> a[1000];
int len[1000];
ll cnt=0;
void djs(int x){
    if(x==y)return;
    for(int i=0;i<n;i++){
        for(int j=0;j<len[i];++j){
            cnt+=2*a[i][j].t;
            djs(j);
            cnt-=2*a[i][j].t;
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;++i){
        int k;
        cin>>k;
        for(int j=0;j<k;++j){
            node x;
            cin>>x.a>>x.t;
            a[i].push_back(x);
            len[i]++;
        }
    }
    for(int i=0;i<q;++i){
        int x;
        cin>>x>>y;
        cnt=0;
        cnt+=w[x]+w[y];
        djs(x);
        cout<<cnt;
    }
    return 0;
}
