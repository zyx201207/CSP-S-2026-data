#include<bits/stdc++.h>
using namespace std;
#define online
constexpr int maxn=2010101;
long long a[maxn];
int cnt[maxn];
struct node{
    int v,c;
    long long dis;
};
int main(){
    #ifdef online
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);cin.tie(0);
    int c,t;cin>>c>>t;
    while(t--){
        int n;cin>>n;
        long long d;cin>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n==1){
            cout<<"0\n";
            continue;
        }
        if(c<=10){
            int ans=0;
            queue<node>q;
            for(int l=1;l<=n;l++){
                q.push(node{0,1,a[l]});
                cnt[0]=1;
                for(int r=l+1;r<=n;r++){
                    while(q.size()&&a[r]-q.front().dis>d){
                        cnt[q.front().v]-=q.front().c;
                        q.pop();
                    }
                    if(!q.size())break;
                    if(cnt[q.front().v]==2){
                        ans++;
                    }
                    int p=cnt[q.front().v];
                    p=min(p,4);
                    q.push(node{q.front().v+1,p,a[r]});
                    cnt[q.front().v+1]+=p;
                }
                while(q.size())q.pop();
                for(int x=0;x<=n;x++)cnt[x]=0;
            }
            cout<<ans<<'\n';
        }
        if(11<=c&&c<=12){
            long long p=(a[2]-a[1]);
            if(d<2*p){
                cout<<"0\n";
                continue;
            }
            long long c=(d/p)*2-1;
            cout<<max(0ll,n-c)<<'\n';
        }
        if(13<=c&&c<=14){
            long long ans=0;
            for(int l=1;l<=n;l++){
                int p=upper_bound(a+1,a+1+n,a[l]+d)-a-1;
                if(p==1)continue;
                int qr=upper_bound(a+1,a+1+n,a[p-1]+d)-a-1;
                int ql=upper_bound(a+1,a+1+n,a[p-2]+d)-a;
                ans+=qr-ql+1;
            }
            cout<<ans<<'\n';
        }
    }
}