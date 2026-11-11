#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;
int n,pp,qq;
struct node{
    ll len;
    char ch;
}p[N],q[N],np[N],nq[N];
ll tot;
inline void solve(node *a,node *na,int &pcnt){
    ll cur=0,mid=tot/2ll;
    bool flg=0;
    for(int i=1;i<=n;i++){
        if(flg==0&&cur+a[i].len>mid){
            na[++pcnt]={mid-cur,a[i].ch};
            na[++pcnt]={a[i].len-(mid-cur),a[i].ch};
            flg=1;
        }else na[++pcnt]=a[i];
        cur+=a[i].len;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i].len>>p[i].ch,tot+=p[i].len;
    for(int i=1;i<=n;i++)q[i]=p[n-i+1];
    solve(q,nq,qq),solve(p,np,pp);
    ll ps=0,qs=0;
    int pr=0,qr=0;
    for(int i=1;i<=pp;i++){
        ps+=np[i].len;
        if(ps==tot/2ll){
            pr=i;
            break;
        }
    }
    for(int i=1;i<=qq;i++){
        qs+=nq[i].len;
        if(qs==tot/2ll){
            qr=i;
            break;
        }
    }
    ll ans1=0,ans2=0;
    ll posj=1;
    for(int i=1,j=1;i<=pr;i++){
        ll tp=np[i].len;
        while(posj+tp-1>nq[j].len){
            if(nq[j].ch!=np[i].ch)ans1+=(nq[j].len-posj+1);
            tp-=(nq[j].len-posj+1);
            posj=1;
            ++j;
        }
        if(nq[j].ch!=np[i].ch)ans1+=tp;
        posj=posj+tp;
        if(posj>nq[j].len)++j,posj=1;
    }
    posj=1;
    for(int i=pr+1,j=qr+1;i<=pp;i++){
        ll tp=np[i].len;
        while(posj+tp-1>nq[j].len){
            if(nq[j].ch!=np[i].ch)ans2+=(nq[j].len-posj+1);
            tp-=(nq[j].len-posj+1);
            posj=1;
            ++j;
        }
        if(nq[j].ch!=np[i].ch)ans2+=tp;
        posj=posj+tp;
        if(posj>nq[j].len)++j,posj=1;
    }
    cout<<min(ans1,ans2);
    return 0;
}