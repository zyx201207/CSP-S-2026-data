#include<bits/stdc++.h>
using namespace std;

const int maxn=505;
const int maxm=5e5+5;
const long long inf=1e18;
int c,n,m,t,q,x,y,s1,s2,k;
int w[maxm];
long long d[maxn][maxn];

vector<pair<int,int>> e[maxm];
void add(int u,int v,int wt){
    e[u].push_back({v,wt});
}

long long get(int x,int y){
    if(x<=y) return d[x][y];
    else return d[y][x];
}

void read(int &x){
    char c=getchar();x=0;
    while(c<'0' || c>'9') c=getchar();
    while(c>='0' && c<='9') x=x*10+c-48,c=getchar();
}
void print(long long x){
    if(x>=10) print(x/10);
    putchar(x%10+48);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    read(c),read(n),read(m),read(t),read(q);
    for(int i=1;i<=m;i++) read(w[i]);
    for(int i=1;i<=n;i++){
        read(k);
        for(int j=0;j<=k-1;j++){
            read(s1),read(s2);
            add(s1,i,s2);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) d[i][j]=inf;
    }
    for(int i=1;i<=n;i++) d[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int a=0;a<e[i].size();a++){
            for(int b=0;b<e[i].size();b++){
                if(a==b) continue;
                int ta=e[i][a].first,tb=e[i][b].first;
                long long tw=e[i][a].second+e[i][b].second;
                d[ta][tb]=min(d[ta][tb],tw);
                d[tb][ta]=min(d[tb][ta],tw);
            }
        }
    }
    for(int h=1;h<=n;h++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                d[i][j]=min(d[i][j],get(i,h)+get(h,j));
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i-1;j++) d[i][j]=d[j][i];
    }
    while(q--){
        read(x),read(y);
        long long ans=inf;
        for(int a=0;a<e[x].size();a++){
            for(int b=0;b<e[y].size();b++){
                int ta=e[x][a].first,tb=e[y][b].first;
                long long tw=e[x][a].second+e[y][b].second;
                ans=min(ans,tw+w[x]+w[y]+d[ta][tb]);
            }
        }
        print(ans),putchar('\n');
    }
    return 0;
}
