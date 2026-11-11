#include<iostream>
#include<queue>
using namespace std;
#define int long long
const int maxn=2e6+10,inf=1e17;
int c,t,n,d,a[maxn],dis[maxn],cnt[maxn];
void slv1(){
    int ans=0;
    queue<int>q;
    for(int st=1;st<=n;st++){
        for(int i=1;i<=n;i++)dis[i]=inf,cnt[i]=0;
        dis[st]=0;
        cnt[st]=1;
        while(q.size())q.pop();
        q.push(st);
        while(q.size()){
            int u=q.front();
            q.pop();
            int l=u+1,r=n,as=u;
            while(l<=r){
                int mid=l+r>>1;
                if(a[mid]-a[u]<=d)as=mid,l=mid+1;
                else r=mid-1;
            }
            for(int j=as;j>u;j--){
                if(dis[j]>dis[u]+1){
                    cnt[j]=cnt[u];
                    dis[j]=dis[u]+1;
                    q.push(j);
                }
                else if(dis[j]==dis[u]+1){
                    cnt[j]+=cnt[u];
                }
                else break;
                if(cnt[j]>2)break;
            }
        }
        for(int i=st;i<=n;i++){
            if(cnt[i]==2)ans++;
        }
    }
    cout<<ans<<'\n';
}
int f(int x,int k){
    if(k==2){
        return (x-1)/2;
    }
    int cnt=x/k;
    int ans=cnt;
    if(x%k==0){
        return (cnt-1)*2;
    }
    if(x%k==k-1){
        return cnt*2;
    }
    if(x%k==1){
        return cnt*2-1;
    }
    return cnt*2;
}
void slv2(){
    int g=a[2]-a[1];
    if(2*g>d){
        cout<<"0\n";
        return;
    }
    int k=d/g;
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=f(n-i,k);
    }
    cout<<ans<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        // if(11<=c&&c<=12){
            // slv2();
        // }
        // if(n<=5e3){
            slv1();
            // continue;
        // }
    }
}