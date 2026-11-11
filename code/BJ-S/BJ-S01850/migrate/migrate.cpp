#include<bits/stdc++.h>
using namespace std;
struct island{
    int id,dist;
};
const int N=2e6+13267;
int c,t,n,d,x[N],ans,m[N],cnt[N];
void check(int i){
    memset(m,0,sizeof m);
    queue<island>q;
    q.push({i,0});
    while(!q.empty()){
        island p=q.front();
        if(m[p.id]==p.dist){
            cnt[p.id]++;
        }
        if(m[p.id]>p.dist||!m[p.id]){
            m[p.id]=p.dist;
            cnt[p.id]=1;
        }
        for(int j=p.id+1;j<=n;j++){
            if(x[j]-x[p.id]>d)break;
            q.push({j,p.dist+1});
        }
        q.pop();
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            check(i);
            for(int j=i+1;j<=n;j++){
                if(cnt[j]==2)ans++;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
