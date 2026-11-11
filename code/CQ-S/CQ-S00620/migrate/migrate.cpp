#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define mid ((l+r)>>1)
#define ls k<<1
#define rs k<<1|1
#define lowbit(x) (x&(-x))
#define ALL(x) (x).begin(),(x).end()
using namespace std;

int rd(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f*=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch-'0'),ch=getchar();
    return x*f;
}
const int N=2e6+5;
int n,d,cid,x[N],f[N],cnt[N],g[N],deq[N],ql,qr,ans;
vector<int> rt;
int calc(int i,int j,int c){
    int cnt=0;
    for(int k=c-2;k<=c+2;k++){
        if(k>i&&k<j&&x[k]-x[i]<=d&&x[j]-x[k]<=d) cnt++;
    }return cnt;
}
void solve(){
    n=rd(),d=rd();
    for(int i=1;i<=n;i++)x[i]=rd();
    if(n==1)return puts("0"),void(0);
    if(cid==11||cid==12){
        int len=x[2]-x[1];d=(d/len);
        if(d<=1) return puts("0"),void(0);
        printf("%lld\n",max(0ll,n-(2*d-1)));   
        return;
    }
    if(cid==13||cid==14){
        for(int c=1;c<=n;c++){
            if(x[c]-x[1]<=d&&x[n]-x[c]<=d){
                for(int i=c-1,j=n;i>=1;i--){
                    while(j>c&&x[j]-x[i]>d) j--;
                    if(j==c) break;
                    int l=j,r=n,R=n+1,L=j;
                    while(l<=r){
                        if(calc(i,mid,c)==1) R=mid,r=mid-1;
                        else l=mid+1;
                    }
                    R--;
                    l=j,r=R;L=R+1;
                    while(l<=r){
                        if(calc(i,mid,c)==2) L=mid,r=mid-1;
                        else l=mid+1;
                    }
                    if(L<=R) ans+=R-L+1;
                }
                for(int i=c+1,j=1;i<=n;i++){
                    while(j<c&&x[i]-x[j]>d) j++;
                    if(j==c) break;
                    int l=j,r=c-1,R=c,L=j;
                    while(l<=r){
                        if(calc(mid,i,c)==1) L=mid,l=mid+1;
                        else r=mid-1;
                    }
                    L++;R=L-1;
                    l=L,r=c-1;
                    while(l<=r){
                        if(calc(i,mid,c)==2) R=mid,l=mid+1;
                        else r=mid-1;
                    }
                    if(L<=R) ans+=R-L+1;
                }
                
                break;
            }
        }printf("%lld\n",ans);ans=0;
        return;
    }
    for(int j=2;j<=n;j++){
        for(int i=0;i<=n;i++)cnt[i]=0;
        ql=1,qr=1,deq[ql]=j,f[j]=0,g[j]=1,cnt[0]=1;
        for(int i=j-1;i;i--){
            while(ql<=qr&&x[deq[ql]]-x[i]>d){
                cnt[f[deq[ql]]]-=g[deq[ql]];
                ql++;
            }
            if(ql>qr) break;
            f[i]=f[deq[ql]]+1,g[i]=cnt[f[deq[ql]]];
            if(g[i]==2) ans++;
            cnt[f[i]]+=g[i],deq[++qr]=i;
            // cout<<i<<' '<<j<<' '<<f[i]<<endl;
        }
    }
    printf("%lld\n",ans);ans=0;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cid=rd();
    int T=rd();while(T--)solve();
    
    return 0;
}
