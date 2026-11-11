#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200005;
int n,ans;
struct node{
    int len,l,r;
    char c;
}q[N];
struct lr{
    int l,r,pos,len;
}l,r;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1,pos=0;i<=n;i++){
        cin>>q[i].len;
        cin>>q[i].c;
        q[i].l=pos+1;
        pos+=q[i].len;
        q[i].r=pos;
    }
    l={q[1].l,q[1].r,1,q[1].r-q[1].l+1};
    r={q[n].l,q[n].r,n,q[n].r-q[n].l+1};
    if(l.len>r.len) l.r=l.l+r.len-1,l.len=l.r-l.l+1;
    else r.l=r.r-l.len+1,r.len=r.r-r.l+1;
    while(l.r<r.l){
        if(q[l.pos].c!=q[r.pos].c) ans+=l.len;
        if(l.r<q[l.pos].r) l.l=l.r+1,l.r=q[l.pos].r;
        else l.pos++,l.r=q[l.pos].r,l.l=q[l.pos].l;
        l.len=l.r-l.l+1;
        if(r.l>q[r.pos].l) r.r=r.l-1,r.l=q[r.pos].l;
        else r.pos--,r.l=q[r.pos].l,r.r=q[r.pos].r;
        r.len=r.r-r.l+1;
        if(l.len>r.len) l.r=l.l+r.len-1,l.len=l.r-l.l+1;
        else r.l=r.r-l.len+1,r.len=r.r-r.l+1;
    }
    cout<<ans;
    return 0;
}
