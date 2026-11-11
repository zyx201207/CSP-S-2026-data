#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int N=2e6+5,M=5005;
const ll V=1e18;
mt19937_64 rd(time(NULL));
int CASE;
ll a[N];
int L[N],R[N];
int n;ll d;
int f[N],g[N];
int dst[M][M];

ll cnt[N],pre[N];

void solve(){
    ll P=rd()%V+V;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>=M){
        cout<<"0\n";
        return;
    }
    int j=1;
    for(int i=1;i<=n;i++){
        while(a[i]-a[j]>d)j++;
        L[i]=j;
    }
    j=n;
    for(int i=n;i>=1;i--){
        while(a[j]-a[i]>d)j--;
        R[i]=j;
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dst[i][j]=1e9;
    for(int i=1;i<=n;i++){
        dst[i][i]=0;
        for(int j=i+1;j<=n;j++){
            dst[i][j]=dst[i][max(i,L[j])]+1;
            dst[j][i]=dst[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        cnt[i]=1;
        pre[i]=1,pre[i-1]=0;
        int k=i;
        for(int j=i+1;j<=n;j++){
            if(dst[i][j]>n)break;
            while(k+1<j && dst[i][k+1]+1<=dst[i][j])k++;
            if(dst[i][k]+1!=dst[i][j])continue;
            cnt[j]=(pre[k]-pre[max(i,L[j])-1]+P)%P;
            pre[j]=(pre[j-1]+cnt[j])%P;
            ans+=(cnt[j]==2);
        }
    }
    cout<<ans<<"\n";
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;cin>>CASE>>T;
    while(T--){
        solve();
    }
    return 0;
}