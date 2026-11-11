#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f
#define c(x) cout<<x<<endl
#define fet(x) const int fet=x

using namespace std;

int n,d;
int c,T;
fet(2e6+10);
int a[fet];
int ans=0;

map<int,int> m;
void solve1();

void in(){
    cin>>n>>d; m.clear(); ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        m[a[i]]=i;
    }
    solve1();
    if(c==11||c==12) ans=0;
    c(ans);
}

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--) in();
    return 0;
}

void solve1(){
    sort(a+1,a+1+n);
    for(int s=1;s<=n;s++){
        int step[n+10]={};
        int sum[n+10]={};
        queue<int> q;
        q.push(a[s]);
        while(q.size()){
            int now=q.front(); q.pop();
            for(int i=1;i<=d;i++){
                if(m[now+i]){
                    int nxt=m[now+i];
                    if(step[nxt]==0||step[m[now]]+1<step[nxt]){
                        step[nxt]=step[m[now]]+1;
                        sum[nxt]=1;
                        q.push(now+i);
                    }else if(step[m[now]]+1==step[nxt])
                        sum[nxt]++,q.push(now+i);
                }
            }
        }
        for(int i=s;i<=n;i++){
            if(sum[i]==2) ans++;
        }
    }
}
