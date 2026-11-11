#include<bits/stdc++.h>
using namespace std;
struct node{
    int l,r;
};
int n,m,a[500005],last[300005],b[500005],val[500005],ans[300005];
vector<node> q;
int Find(int g){
    int l=0,r=q.size()-1;
    while(l<r){
        int mid=l+r+1>>1;
        if(q[mid].l>g) l=mid;
        else r=mid-1;
    }
    return l;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],val[i]=i;
    for(int i=n;i>=1;i--){
        if(last[a[i]]==0) last[a[i]]=i;
        else q.push_back({i,last[a[i]]});
        b[i]++;
        b[last[a[i]]]--;
        int t=Find(last[a[i]]),L=last[a[i]];
        while(t<q.size()&&q[t].l>=L){

            b[q[t].l]++;
            b[q[t].r]--;
            L=q[t].r;
            t=Find(q[t].r);
        }
    }
    for(int i=1;i<=n;i++) b[i]+=b[i-1];
    for(int i=n;i>=1;i--){
        if(i==last[a[i]]) ans[a[i]]=val[i]-b[i];
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
