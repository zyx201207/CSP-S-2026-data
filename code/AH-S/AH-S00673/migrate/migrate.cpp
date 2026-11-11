#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int c,t;
int n;
long long a[MAXN];
int nex[MAXN];
int dis[MAXN];
long long cnt[MAXN];
long long d;
long long ans;
int iread(){
    int res=0,sig=1;
    char c;
    c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-') sig=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        res=res*10+c-'0';
        c=getchar_unlocked();
    }
    return res*sig;
}
long long lread(){
    long long res=0,sig=1;
    char c;
    c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-') sig=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        res=res*10+c-'0';
        c=getchar_unlocked();
    }
    return res*sig;
}
void dfs(int st,int step){
    if(step<dis[st]){
        dis[st]=step;
        cnt[st]=1;
    }else if(step==dis[st]){
        cnt[st]++;
    }else{
        return ;
    }
    if(st==n) return ;
    for(int i=st+1;i<=nex[st];i++){
        dfs(i,step+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cin>>c>>t;
    c=iread();
    t=iread();
    while(t--){
        //cin>>n>>d;
        n=iread();
        d=lread();
        ans=0;
        for(int i=1;i<=n;i++){
            //cin>>a[i];
            a[i]=lread();
        }
        for(int i=1;i<=n;i++){
            int pos=upper_bound(a+1,a+n+1,a[i]+d)-a;
            nex[i]=pos-1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cnt[j]=0;
                dis[j]=0x3f3f3f3f;
            }
            dfs(i,0);
            for(int j=1;j<=n;j++){
                if(cnt[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
