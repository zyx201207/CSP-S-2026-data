#include<bits/stdc++.h>
using namespace std;
int n,m,c,q,a,u,v,w[500005],ans,k,x,y,cnt[500005];
deque<int> s[500005],d[500005];
int value[25][500005];/*
int dfs(int now,int des,int dep){
    int ans=0x7fffffff;
    if(cnt[now]){
        return dep;
    }
    cnt[now]++;
    for(int i=0;i<d[now].size();i++){
        int sta=d[now][i];
        for(int j=0;j<s[d[now][i]].size();j++){
            int v=value[sta][s[sta][j]];
            ans=min(ans,v+value[sta][now]);
            dfs(s[sta][j],des,ans);
        }
    }
    cnt[now]--;
    return ans;
}*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>x>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a;
            cin>>value[i][a];/*
            s[i].push_back(a);
            d[a].push_back(i);*/
        }
    }
    while(q--){
        cin>>x>>y;/*
        memset(cnt,0,sizeof(cnt));
        cout<<dfs(x,y,0)<<"\n";
        */
        cout<<value[x][y]+value[y][x]<<"\n";
    }
	return 0;
}
