//准考证号：GZ-S00420  学校：黔南布依族苗族自治州都匀第一中学  姓名：孙祖兴
#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,w[20010],t[510][20010],a[510][20010],s[20010][21],k[510],xs[20010];

long long dfs(int x,int y){
    xs[x]=-1;
    long long tans=210000000000;
    if(x==y)return 0;
    for(int i=1;i<=s[x][0];i++){
        if(t[s[x][i]][y]!=0)return t[s[x][i]][x]+t[s[x][i]][y];
    }
    for(int i=1;i<=s[x][0];i++){
        for(int j=0;j<k[s[x][i]];j++){
            if(xs[a[s[x][i]][j]]==0)tans=min(tans,dfs(a[s[x][i]][j],y)+t[s[x][i]][a[s[x][i]][j]]+t[s[x][i]][x]);
        }
    }
    return tans;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];

    for(int i=0;i<n;i++){
        cin>>k[i];
        for(int j=0;j<k[i];j++){
            cin>>a[i][j];
            cin>>t[i][a[i][j]];
            s[a[i][j]][s[a[i][j]][0]+1]=i;
            s[a[i][j]][0]++;
        }
    }

    for(int iiii=1;iiii<=q;iiii++){
        int x,y;
        cin>>x>>y;
        cout<<dfs(x,y)+w[x]+w[y]<<endl;
    }
    return 0;
}
