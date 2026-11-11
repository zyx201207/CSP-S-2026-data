#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e6;
const int M=2e4;
int used[N];
ll read(){
    char c;
    c=getchar();
    ll re=0;
    ll flag=1;
    if(c=='-')flag=-1;
    else{
        re=c-'0';
    }
    while(1){
        c=getchar();
        if(c<'0'||c>'9')break;
        re=re*10+(c-'0');
    }
    return re*flag;
}
char W[100000000];
void write(ll r){
    char style;
    if(r<0){
        style='-';
        putchar(style);
        r=0-r;
    }
    if(r==0){
        style='0';
        putchar(style);
        return ;
    }
    ll cntw=0;
    while(r){
        cntw++;
        W[cntw]=r%10+'0';
        r/=10;
    }
    for(int i=cntw;i>=1;i--)putchar_unlocked(W[i]);
}

ll n,m,c,d,q;
struct side{
    ll from;
    ll endd;
    ll next;
    ll vea;
}mp[N];
ll cnta;
ll head[N];
void add(ll from,ll endd,ll vea){
    cnta++;
    mp[cnta].endd=endd;
    mp[cnta].from=from;
    mp[cnta].vea=vea;
    mp[cnta].next=head[from];
    head[from]=cnta;
}

struct e{
    ll vea;
    int num;
    friend bool operator < (e q,e w){
        return q.vea>w.vea;
    }
};
priority_queue<e> p;
e pi,pp;
ll dis[N];
bool book[N];
ll dij(int fir,int goal){
    pi.num=fir;
    pi.vea=0;
    dis[fir]=0;
    p.push(pi);
    while(!p.empty()){
        pi=p.top();
        p.pop();
        if(book[pi.num])continue;
        else book[pi.num]=1;
        int u=pi.num;
        if(u==goal)break;
        for(int i=head[u];i;i=mp[i].next){
            int v=mp[i].endd;
            if(dis[v]>dis[u]+mp[i].vea){
                dis[v]=dis[u]+mp[i].vea;
                pp.num=v;
                pp.vea=dis[v];
                p.push(pp);
            }
        }
    }
    return dis[goal];
}
 void clean(){
    while(!p.empty())p.pop();
    for(int i=0;i<=m*(d+2);i++){
        dis[i]=1e18;
        book[i]=0;
    }
 }
int main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();
    n=read();
    m=read();
    d=read();
    q=read();
    /*write(c);
    write(n);
    write(m);
    write(d);
    write(q);
    putchar('\n');*/
    for(int i=1;i<=m;i++){
        int v;
        v=read();
        //write((long long)v);
        //putchar('\n');
        used[i]=1;
        add(i,i+(m+1),v);
        add(i+(m+1),i,v);
    }
    for(int i=1;i<=n;i++){
        int k;
        k=read();
        ll last=0;
        for(int j=1;j<=k;j++){
            ll num,v;
            num=read();
            v=read();
            used[num]++;
            add(num+(m+1),num+(m+1)*used[num],v);
            add(num+(m+1)*used[num],num+(m+1),v);
            if(j>1){
                add(num+(m+1)*used[num],last+(m+1)*used[last],0);
                add(last+(m+1)*used[last],num+(m+1)*used[num],0);
            }
            last=num;
        }
    }
    for(int i=1;i<=q;i++){
        ll start,goal;
        start=read();
        goal=read();
        clean();
        ll ans=dij(start,goal);
        write(ans);
        putchar_unlocked('\n');
    }
    return 0;
}

