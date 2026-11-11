#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+9;
// struct q{
//     int x,t; 
// };
int C,n,m,d,q,w[N],l,r,b[N],c[509][N],e[509][N],k[509];
ll v[N];
ll at[30][N],ax[30][N];
void f(int x,ll t){
    if(x==r){
        v[r]=min(t,v[r]);
        return ;
    }
    if(v[x]<=t)return ;
    for(int i=1;i<=b[x];i++){
        int t=ax[i][x];
        for(int j=1;j<=k[t];j++){
            int t=v[c[t][j]];
            v[c[t][j]]=min(v[c[t][j]],(t+e[t][j]+at[i][x]));
            f(c[t][j],t+e[t][j]+at[i][x]);
            v[c[t][j]]=t;
        }
    }
}
int main(){
    freopen("subway1.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int t;cin>>t;
            c[i][j]=t;
            cin>>at[++b[t]][t];
            e[i][j]=at[++b[t]][t];
            ax[b[t]][t]=i;
        }
    }
    for(int i=1;i<=q;i++){
        for(int j=1;j<=m;j++)v[j]=1e18;
        cin>>l>>r;
        v[l]=1;
        f(l,1ll*0);
        cout<<v[r]+w[l]+w[r]<<endl;
    }
    return 0;
}