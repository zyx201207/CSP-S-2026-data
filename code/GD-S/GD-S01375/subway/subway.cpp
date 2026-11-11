#include<bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;
const int N = 510;
const int M = 500010;
const int L = N+M;
int w[M],head[L],to[L*2],next_[L*2],cnt;
ll edge[L*2],dis[M+N];
int c,n,m,d,q;
void add(int u,int v,ll x){
    cnt++;
    next_[cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    edge[cnt] = x;
}
void spfa(int x){
    memset(dis,63,sizeof(dis));
    queue<int> q;
    q.push(x);
    dis[x] = 0;
    while(q.size()){
        int tmp = q.front();
        // cout<<tmp<<" ";
        q.pop();
        for(int i=head[tmp];i;i=next_[i]){
            int v = to[i];
            ll l=edge[i];
            if(dis[tmp]+l<dis[v]){
                // cout<<tmp<<" -> "<<v<<": "<<dis[tmp]+l<<endl;
                dis[v] = dis[tmp]+l;
                q.push(v);
            }
        }
    }
    // for(int i=1;i<=ztcnt;i++) cout<<dis[i]<<" ";
}
int getin(){
    int flag = 1,ans=0;
    char c = getchar();
    while(!isdigit(c)){
        if(c=='-') flag = -1;
        c = getchar();
    }
    while(isdigit(c)){
        ans *= 10;
        ans += c-'0';
        c = getchar();
    }
    return ans * flag;
}
void print(ll x,bool flag=1){
    if(x<0){
        putchar('-');
        x = -x;
    }
    if(x==0){
        if(flag) putchar('0');
        return ;
    }
    print(x/10,0);
    putchar(x%10+'0');
}
struct question{
    ll x,y,i,ans;
    bool operator < (question other){
        return x<other.x;
    }
}questions[100010];
bool cmp(question a,question b){
    return a.i<b.i;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=getin(),n=getin(),m=getin(),d=getin(),q=getin();
    for(int i=1;i<=m;i++) w[i]=getin();
    for(int i=1;i<=n;i++) {
        int k=getin();
        for(int j=1;j<=k;j++){
            int u=getin(),t=getin();
            add(u,i+m,t);
            add(i+m,u,t);
        }
    }
    for(int i=1;i<=q;i++){
        questions[i].x = getin();
        questions[i].y = getin();
        questions[i].i = i;
        if(questions[i].x>questions[i].y) swap(questions[i].x,questions[i].y);
    }
    sort(questions+1,questions+1+q);
    int lx = -1;
    for(int i=1;i<=q;i++){
        int x = questions[i].x,y = questions[i].y;
        if(x!=lx){
            spfa(x);
            lx = x;
        }
        questions[i].ans = dis[y]+w[x]+w[y];
    }
    sort(questions+1,questions+1+q,cmp);
    for(int i=1;i<=q;i++){
        print(questions[i].ans);
        putchar('\n');
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
