#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=5e5+10;
const ll maxm=3e5+10;
ll n,m,a[maxn],cnt[maxn],len,rec[maxm];
struct pir{
    ll l,r,nxt;
    bool operator < (const pir &other)const{
        return l<other.l;
    }
};
vector <pir> p;
vector <ll> t;
bool cmp(ll x,ll y){
    return p[x].r>p[y].r;
}
void fillin1(){
    ll tmp=len+1;
    for(ll i=0;i<len;i++){
        while(tmp-1>=0&&p[tmp-1].l>p[t[i]].r)
            tmp--;
        p[t[i]].nxt=tmp;
    }
    return ;
}
void fillin2(){
    ll tmp=len+1;
    for(ll i=n;i>=1;i--){
        while(tmp-1>=0&&p[tmp-1].l>=i)
            tmp--;
        cnt[i]++;
        cnt[p[tmp].l]--;
        //cout<<i<<" "<<p[tmp].l<<endl;
    }
    return ;
}
//3 1 2 1 3 2 3 1 2 1
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    p.push_back({0,0,0});
    for(ll i=1;i<=n;i++)
        scanf("%lld",a+i);
    for(ll i=n;i>=1;i--){
        if(rec[a[i]]>0){
            p.push_back({i,rec[a[i]],0});
            len++;
            t.push_back(len);
        }
        else
            rec[a[i]]=i;
    }
    memset(rec,0,sizeof(rec));
    p.push_back({n+1,n+1,0});
    sort(p.begin(),p.end());
    sort(t.begin(),t.end(),cmp);
    fillin1();
    /*
    printf("p:\n");
    for(ll i=1;i<=len;i++)
        printf("%lld %lld %lld\n",p[i].l,p[i].r,p[i].nxt);
    printf("t:");
    for(ll i=0;i<len;i++)
        printf("%lld %lld\n",t[i],p[t[i]].r);
    printf("\n");
    */
    t.clear();t.push_back(0);
    for(ll i=1;i<=len+1;i++)
        t.push_back(p[i].l-p[i-1].l);
    //printf("\n");
    for(ll i=1;i<=len;i++){
        t[p[i].nxt]+=t[i];
        //printf("%lld ",t[i]);
        cnt[p[i].r]+=t[i];
        cnt[p[p[i].nxt].l]-=t[i];
        /*
        for(ll i=1;i<=n+2;i++)
            printf("%lld ",cnt[i]);
        printf("\n");
        */
    }
    fillin2();
    for(ll i=1;i<=n;i++){
        cnt[i]+=cnt[i-1];
        //printf("%lld ",cnt[i]);
        rec[a[i]]+=cnt[i];
    }
    //printf("\n");
    for(ll i=1;i<=m;i++)
        printf("%lld ",rec[i]);
    return 0;
}
