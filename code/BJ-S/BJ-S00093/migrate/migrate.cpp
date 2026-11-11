#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,a[1000010];
long long Floyd(){
    long long sum=0;
    long long dist[100000][100000],cnt[10000][10000];
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(dist[i][k]+dist[k][j]<dist[i][j]){
                    cnt[i][j]=0;
                    dist[i][j]=dist[i][k]+dist[k][j];
                }else if(dist[i][k]+dist[k][j]==dist[i][j]){
                    cnt[i][j]++;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j>=n;j++){
            if(cnt[i][j]==2)sum++;
        }
    }
    return sum;
}
vector<long long> adj[2000010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=1;j<i;j++){
                if(a[i]-a[j]<=d){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        cout<<Floyd()<<'\n';
    }
    return 0;
}
