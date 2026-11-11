#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[1000005],k[1000005],x[1000005],y[1000005];
vector<long long> a[1000005];
vector<long long> t[1000005];
vector<pair<long long,long long>> g[100005];
//struct node
//{
//    long long me,id,l;

//};
//vector<node> g[500005];
long long ans=0;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++){
        cin>>w[i];
    }
    for(long long i=1;i<=n;i++){
        cin>>k[i];
        for(long long j=1;i<=k[i];i++){
            long long ma,mt;
            cin>>ma>>mt;
            a[i].push_back(ma);
            t[i].push_back(mt);
            
        }
    }

    for(long long i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    if(c>=7 && c<=11 || c==0){
        for(long long i=1;i<=n;i++){
            if(k[i]>1){
                long long u=a[i][0],v=a[i][1];
                g[u].push_back({v,t[i][1]+t[i][0]});
                g[v].push_back({u,t[i][1]+t[i][0]});
            }
        }
        for(long long i=1;i<=q;i++){
            long long memo[500005];
            long long u=x[i],v=y[i];
            queue<pair<long long,long long>> q;
            q.push({u,0});
            memo[u]=0;
            while(q.size()){
                long long me=q.front().first;
                long long ml=q.front().second;
                for(int nn=0;nn<g[me].size();nn++){
                    int next=q.front().first;
                    int nt=q.front().second;
                    int nl=ml+nt;
                    if(nl<memo[next]){
                        memo[next]=nl;
                        q.push({next,nl});
                    }
                }
            }
            cout<<memo[v]+w[u]+w[v]<<endl;
        }
    }else if(c>=12 & c<=15){

    }

    return 0;
}
