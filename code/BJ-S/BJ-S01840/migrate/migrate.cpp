#include<bits/stdc++.h>
#define gc getchar
using namespace std;
using ll=long long;
ll rdint(){
    ll x=0;int f=1;char c=gc();
    while(!isdigit(c)){
        if(c=='-') f=-1;c=gc();
    }while(isdigit(c)) x=x*10+c-'0',c=gc();
    return x*f;
}
const int N=2e6+10;
ll d,x[N];int n;
int f[N][3][3][2],nxt[N];
bool ok[3][3];int t[3];
void slv(){
    cin>>n>>d;
    //2~n+1
    //for(int i=2;i<=n+1;i++) cin>>x[i];
    for(int i=2;i<=n+1;i++) x[i]=rdint();
    x[0]=-4e18;x[1]=-4e18;
    int it=n+1;
    for(int i=n+1;i>=0;i--){
        while(x[it]-x[i]>d) it--;
        nxt[i]=it;
    }
    for(int i=0;i<=n+1;i++){
        for(int a=0;a<=2;a++)
        for(int b=0;b<=2;b++)
        for(int c=0;c<=1;c++) f[i][a][b][c]=0;
        //memset(f[i],0,sizeof(f[i]));
    }
    ll ans=0;ll cost=0;
    for(int i=2;i<=n+1;i++){
        memset(ok,0,sizeof(ok));
        memset(t,0,sizeof(t));
        f[i][0][0][0]++;
        if(nxt[i]==i) continue;
        int p0=nxt[i];
        int p1=max(i,nxt[i-1]);
        int p2=max(i,nxt[i-2]);
        for(int a=0;a<3;a++){
            for(int b=0;b<3;b++){
                ok[a][b]=(x[nxt[i]-b]-x[i-a]<=d);
            }
        }
        for(int a=2;a>=0;a--){
            for(int b=a;b>=0;b--){
                for(int z=0;z<3;z++) t[z]=b*ok[1][z]+a*ok[2][z];
                ans+=1ll*(p0-p1)*f[i][a][b][1];
                if(1-b>=0) ans+=1ll*(p1-p2)*f[i][a][b][1-b];
                if(1-a-b>=0) ans+=1ll*(p2-i)*f[i][a][b][1-a-b];
                for(int c=0;t[0]+c+1<=2;c++){
                    //if(!f[i][a][b][c]) continue;
                    //if(f[i][a][b][c]) cout<<i<<' '<<a<<' '<<b<<' '<<c<<'\n';
                    //if(c+1==2) ans+=1ll*(p0-p1)*f[i][a][b][c];
                    //if(b+c+1==2) ans+=1ll*(p1-p2)*f[i][a][b][c];
                    //if(a+b+c+1==2) ans+=1ll*(p2-i)*f[i][a][b][c];
                    /*if(f[i][a][b][c]){
                        cout<<i<<' '<<a<<' '<<b<<' '<<c<<' '<<t[2]<<' '<<t[1]<<' '<<t[0]<<'\n';
                    }*/
                    //if(t[0]+c+1<=2) 
                    t[1]=min(t[1]+1,2);t[2]=min(t[2]+1,2);
                    f[nxt[i]][t[2]][t[1]][t[0]+c+1-1]+=f[i][a][b][c];
                }
            }
        }
    }cout<<ans<<'\n';
}
int tid;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>tid>>t;
    while(t--) slv();
    return 0;
}
