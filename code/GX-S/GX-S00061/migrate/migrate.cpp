#include<bits/stdc++.h>
#define LL long long
using namespace std;
int c,t;
const int MAXN = 2e6+100;
LL n,d,pos[MAXN],ans=0,res=0;
bool check(int l,int r,int num){
    int now=l,next=l+1,cnt=0;
    while(1){
        while(pos[next]-pos[now]<=d)++next;
        --next;
        ++cnt;
        now=next;
        if(cnt>num)return 0;
        if(next>=r)return 1;
    }
}
void dfs(int now,int r,int cnt,int lim){
    if(cnt>lim){return;}
    if(now==r){++res;return;}
    for(int i=now+1;i<=r;++i){
        if(pos[i]-pos[now]<=d){
            dfs(i,r,cnt+1,lim);
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;++i)cin>>pos[i];
        for(int r=2;r<=n;++r){
            for(int l=1;l<r;++l){
                res=0;
                LL dist=0;
                bool flag=false;
                int next=l+1,now=l;
                if(next==r)dist=1;
                while(next<r){
                    while(pos[next]-pos[now]<=d)++next;
                    --next;
                    if(next==now){flag=true;break;}
                    now=next,++dist;
                }
                if(flag)continue;
                dfs(l,r,0,dist);
                ans+=(res==2);

            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
