#include<bits/stdc++.h>
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define req(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define ll long long
#define ull unsigned ll
using namespace std;
const int N=5005;
const int M=2e6+5;
const ll INF=(1ll<<60);
ll c,t,n,d,x[M],f[N],h[N],pre[M],mn,cnt[N],nxt[M];
void del(ll tmp){
    h[f[tmp]]-=cnt[tmp];
    if(h[f[tmp]]==0)while(h[mn]==0)mn++;
}
ll calc1(ll i){
    ll L=1,R=i-1,ans=i;
    if(x[i]-x[1]<=d)return 0;
    while(L<=R){
        ll mid=(L+R)/2;
        if(x[i]-x[mid]<=d){
            R=mid-1;
            ans=mid;
        }
        else L=mid+1;
    }
    return ans;
}
ll calc2(ll i){
    ll L=i+1,R=n,ans=i;
    if(x[n]-x[i]<=d)return n+1;
    while(L<=R){
        ll mid=(L+R)/2;
        if(x[mid]-x[i]<=d){
            L=mid+1;
            ans=mid;
        }
        else R=mid-1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c>=11&&c<=12){
        while(t--){
            cin>>n>>d;
            rep(i,1,n)cin>>x[i];
            if(n==1){
                cout<<"0\n";
                continue;
            }
            ll len=x[2]-x[1];
            if(d/len<2){
                cout<<"0\n";
                continue;
            }
            ll sz=(d/len)*2;
            if(n<sz){
                cout<<"0\n";
                continue;
            }
            cout<<n-sz+1<<"\n";
        }
        return 0;
    }
    if(c>=13&&c<=14){
        while(t--){
            cin>>n>>d;
            rep(i,1,n)cin>>x[i];
            if(n==1){
                cout<<"0\n";
                continue;
            }
            rep(i,1,n){
                pre[i]=calc1(i);
                nxt[i]=calc2(i);
                if(pre[i]!=i&&pre[i]!=i-1)h[pre[i]]++;
            }
            ll ans=0;
            rep(i,1,n)if(nxt[i]!=n+1&&nxt[i]!=i&&nxt[i]!=i+1){
                ans+=h[nxt[i]-1];
            }
            cout<<ans<<"\n";
        }
        return 0;
    }
    while(t--){
        cin>>n>>d;
        rep(i,1,n)cin>>x[i];
        rep(i,1,n){
            pre[i]=INF;
            rep(j,1,i-1)if(x[i]-x[j]<=d){
                pre[i]=min(pre[i],j*1ll);
            }
        }
        ll ans=0;
        rep(i,1,n){
            memset(h,0,sizeof(h));
            ll nowL=i;
            f[i]=0,h[0]=cnt[i]=1,mn=0;
            rep(j,i+1,n){
                if(pre[j]==INF)break;
                ll L=max(i*1ll,pre[j]);
                while(nowL<L)del(nowL++);
                f[j]=mn+1;
                cnt[j]=h[mn];
                if(cnt[j]==2)ans++;
                h[f[j]]+=cnt[j];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}