#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int m,c,t;
long long a[N],d,v[N];
long long bfs(int s,int e,int m,long long d){
    bool g = true;
    long long sum = 0,t = 0,l = 1;
    queue <int> q;
    q.push(s);
    int k = 0;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int i=1;i<=d;i++){
            int xx = p+i;
            if(xx>0 && xx<=m){
                v[xx] = v[p]+1;
                q.push(xx);
                if(xx==e){
                    if(g){
                        t = v[xx];
                        g = false;
                    }
                    if(t==v[xx]) sum++;
                    else if(v[xx]>t) return sum;
                }
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>m>>d;
        for(int i=1;i<=m;i++) cin>>a[i];
        long long ans = 0;
        for(int i=1;i<m;i++){
            for(int j=i+1;j<=m;j++){
                long long cnt = bfs(i,j,m,d);
                if(cnt==2) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
