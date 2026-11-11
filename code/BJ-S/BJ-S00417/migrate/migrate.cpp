#include<bits/stdc++.h>
using namespace std;
int n,d,cnt=0;
long long land[20005]={0};
int mem[20005][20005]={0};
void dfs(int now,int step){
    if(now>n) return;
    for(int t=1;t<=n-now;t++){
        if(land[now+t]-land[now]<=step) mem[now][now+t]++;
        dfs(now+t,d);
        for(int t1=1;t1<t;t1++) mem[now][now+t]+=mem[now][now+t1]*mem[now+t1][now+t];
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,ti;
    cin>>c>>ti;
    for(int abc=0;abc<ti;abc++){
    cnt=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>land[i];
    dfs(1,d);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(mem[i][j]==2) cnt++;
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<=n;i++){
        land[i]=0;
        for(int j=0;j<=n;j++) mem[i][j]=0;
    }
    }
    return 0;
}
