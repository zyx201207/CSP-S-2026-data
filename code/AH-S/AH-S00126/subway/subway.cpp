#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int w[500010];
int problem[100010][2];
struct qw{
    int a,t;
};
int stop[500010];
vector<qw> line[510];
bool check_line(int x,int v){
    for(int i=0;i<line[v].size();i++){
        if(line[v][i].a==x) return true;
    }
    return false;
}
int zhi[510];
bool bzhi[10000000];

signed main(){
    for(int i=1;i<=500005;i++){
        stop[i]=1;
    }
    int flag=0;
    for(int i=2;i<=3600;i++){
        if(!bzhi[i]){
            zhi[++flag]=i;
            cout<<i<<' ';
            for(int j=i*2;j<=3600;j+=i){
                if(!bzhi[j]){
                    bzhi[j]=true;
                }
            }
            if(flag==500) break;
        }
    }
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%lld",&k);
        int a,t;
        for(int j=1;j<=k;j++){
            scanf("%lld%lld",&a,&t);
            line[i].push_back({a,t});
            stop[a]*=zhi[i];
        }
    }
    int xx,yy;
    for(int i=1;i<=q;i++){
        scanf("%lld%lld",&xx,&yy);
        if(__gcd(stop[xx],stop[yy])!=1){
            cheek()
        }
    }

    return 0;
}
