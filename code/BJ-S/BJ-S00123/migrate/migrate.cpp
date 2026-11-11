#include<bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d;
long long x[2000005];
vector<int> v[2000005];
int to[2000005];
int rem[2000005];
int dist[2000005];
int num[2000005];
queue<int> q;
long long ans=0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        ans=0;
        for(int i=1;i<=n;i++){
            to[i]=rem[i]=0;
            v[i].clear();
            dist[i]=1e9;
            num[i]=0;
        }
        for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<=n;j++){
                if(x[j]-x[i]<=d){
                    v[i].push_back(j);
                    to[j]++;
                    rem[j]++;
                }
            }
            /*cout<<i<<":"<<endl;
            for(int j=i;j<=n-1;j++){
                for(int k=0;k<v[j].size();k++)
                cout<<v[j][k]<<" ";
                cout<<endl;
            }
            cout<<endl;*/
            for(int j=i;j<=n;j++)
            dist[j]=1e9,num[j]=0;
            dist[i]=0;
            num[i]=1;
            q.push(i);
            while(!q.empty()){
                int now=q.front();
                q.pop();
                for(int i=0;i<v[now].size();i++){
                    int p=v[now][i];
                    if(dist[now]+1<dist[p]){
                        dist[p]=dist[now]+1;
                        num[p]=num[now];
                    }
                    else if(dist[now]+1==dist[p])
                    num[p]+=num[now];
                    to[p]--;
                    if(to[p]==0){
                        if(num[p]==2)ans++;
                        q.push(p);
                    }
                }
            }
            /*cout<<i<<":"<<endl;
            for(int j=i;j<=n;j++){
                cout<<dist[j]<<" "<<num[j]<<"*";
            }
            cout<<endl;*/
            for(int j=i;j<=n;j++)to[j]=rem[j];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
