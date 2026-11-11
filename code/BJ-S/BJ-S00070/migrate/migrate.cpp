#include<iostream>
#define endl '\n'
using namespace std;
using ll=long long;
int c,t,n,sum;
ll d,x[2000005];
void dfs(int w,int v,ll lst,int l){
    if(sum>2) return;
    if(w==v){sum+=(!l and x[v]-lst<=d); return;}
    if(l and x[w]-lst<=d) dfs(w+1,v,x[w],l-1);
    dfs(w+1,v,lst,l);
}
int main(){
    freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(n==1){cout<<0<<endl; continue;}
        if(c==11 or c==12){
            ll t=d/(x[2]-x[1]);
            cerr<<t<<endl;
            if(t<2){cout<<0<<endl; continue;}
            cout<<max(0ll,n-2*t+1)<<endl;
            continue;
        }
        for(int u=1;u<=n;u++) for(int v=u+1;v<=n;v++){
            sum=0;
            for(int l=0;!sum and l<=v-u;l++) dfs(u+1,v,x[u],l);
            if(sum==2) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}