//I can't go to NOIP2026qwq
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
inline int rd(){
    char c='?';
    int res=0,fg=1;
    while(!isdigit(c)){
        c=getchar_unlocked();
        if(c=='-') fg=-1;
    }
    while(isdigit(c)){
        res=res*10+c-'0';
        c=getchar_unlocked();
    }
    return res*fg;
}
int a[2000001];
int rt[2000001];//TODO:add next weidu
void init(int n){
    for(int j=1;j<=24;j++){
        for(int i=1;i<=n;i++){
            //rt[i][j]=rt[rt[i][j-1]][j-1];
        }
    }
}
int dist[2000001];
int nums[2000001];
bool vis[2000001];
int bfs(int s,int n){
    memset(dist,0x3f,sizeof(dist));
    memset(nums,0,sizeof(nums));
    queue<int> q;
    q.push(s);
    dist[s]=0;
    nums[s]++;
    while(q.size()){
        int f=q.front();
        q.pop();
        vis[f]=0;
        for(int i=f+1;i<=rt[f];i++){
            if(dist[i]==dist[f]+1) nums[i]+=nums[f];
            else if(dist[i]>dist[f]+1){
                dist[i]=dist[f]+1;
                nums[i]=nums[f];
                if(!vis[i]) q.push(i),vis[i]=1;
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++){
        res+=(nums[i]==2);
        //cout<<s<<' '<<i<<' '<<nums[i]<<'\n';
    }
    return res;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c=rd(),t=rd();
    while(t--){
        int n=rd(),d=rd();
        for(int i=1;i<=n;i++){
            a[i]=rd();
        }
        if(c==11||c==12){
            int kd=a[2]-a[1];
            int p=min(n,d/kd);
            if(p<=1){
                cout<<0<<'\n';
                continue;
            }
            //cout<<n<<' '<<kd<<' '<<d<<'\n';
            cout<<max(n-2*p+1,0ll)<<'\n';
            continue;
        }
        int l=1,r=0;
        while(r<n){
            r++;
            while(l<=r&&a[r]-a[l]>d) rt[l]=r-1,l++;
        }
        for(int i=l;i<=n;i++) rt[i]=n;
        //init();
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=bfs(i,n);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
