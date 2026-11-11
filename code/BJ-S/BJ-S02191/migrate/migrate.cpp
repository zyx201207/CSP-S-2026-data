#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
const int N=5005;
vector<int> S[N];
int p[N],q[N];
queue<int> Q;
ll a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--){
        int n;
        ll d;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",a+i);
            if(!(c==11||c==12)) S[i].clear();
        }
        if(c==11||c==12){
            ll x=d/(a[2]-a[1]);
            if(x<=1||n-2*x+1<=0) printf("0\n");
            else printf("%lld\n",n-2*x+1);
        }
        else{
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(a[j]-a[i]<=d){
                        S[i].push_back(j);
                        S[j].push_back(i);
                    }
                }
            }
            int cnt=0;
            for(int i=1;i<=n;i++){
                memset(p,-1,sizeof(p));
                memset(q,0,sizeof(q));
                Q.push(i);
                p[i]=0;
                q[i]=1;
                while(!Q.empty()){
                    int s=Q.front();
                    Q.pop();
                    for(int j=0;j<S[s].size();j++){
                        if(S[s][j]<s) continue;
                        if(p[S[s][j]]==-1){
                            p[S[s][j]]=p[s]+1;
                            q[S[s][j]]=q[s];
                        }
                        else if(p[S[s][j]]>p[s]+1){
                            p[S[s][j]]=p[s]+1;
                            q[S[s][j]]=q[s];
                        }
                        else if(p[S[s][j]]==p[s]+1){
                            q[S[s][j]]++;
                        }
                        else continue;
                        Q.push(S[s][j]);
                    }
                }
                for(int j=i+1;j<=n;j++){
                    if(q[j]==2) cnt++;
                }
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}
