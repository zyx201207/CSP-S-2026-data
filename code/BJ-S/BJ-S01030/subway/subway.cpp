#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long ans=0x3f3f3f3f3f;
long long w[500010];
struct Subway{
    int k;
    long long a[1010],t[1010];
    bool f=false;
}line[1010];
struct Station{
    int num=0;
    int line_num[110],line_order[110];
}sta[500010];
void solve(int start,int ending,int now_sta,int now_line,int now_order,long long now_cost){
    if(now_sta==ending){
        now_cost+=(line[now_line].t[now_order]+w[ending]);
        ans=min(ans,now_cost);
        return ;
    }
    if(now_cost>=ans) return ;
    for(int i=1;i<=line[now_line].k;i++){
        if(i==now_order) continue;
        now_sta=line[now_line].a[i];
        if(now_sta==ending){
            now_cost+=(line[now_line].t[i]+w[ending]);
            ans=min(now_cost,ans);
            return ;
        }
        if(sta[now_sta].num<=1) continue;
        for(int j=1;j<=sta[now_sta].num;j++){
            long long new_cost=now_cost+(line[now_line].t[i]+line[sta[now_sta].line_num[j]].t[sta[now_sta].line_order[j]]);
            int new_line=sta[now_sta].line_num[j];
            int new_order=sta[now_sta].line_order[j];
            if(new_line==now_line) continue;
            if(line[new_line].f==true) continue;
            line[new_line].f==true;
            solve(start,ending,now_sta,new_line,new_order,new_cost);
            line[now_line].f=false;
        }
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>line[i].k;
        for(int j=1;j<=line[i].k;j++){
            cin>>line[i].a[j]>>line[i].t[j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=line[i].k;j++){
            sta[line[i].a[j]].line_num[++sta[line[i].a[j]].num]=i;
            sta[line[i].a[j]].line_order[sta[line[i].a[j]].num]=j;
        }
    }
    while(q--){
        int x,y;
        ans=0x3f3f3f3f3f3f;
        for(int i=1;i<=n;i++){
            line[i].f=false;
        }
        cin>>x>>y;
        for(int i=1;i<=sta[x].num;i++){
            line[sta[x].line_num[i]].f=true;
            solve(x,y,x,sta[x].line_num[i],sta[x].line_order[i],w[x]+line[sta[x].line_num[i]].t[sta[x].line_order[i]]);
            line[sta[x].line_num[i]].f=false;
        }
        cout<<ans<<endl;
    }
    return 0;
}
