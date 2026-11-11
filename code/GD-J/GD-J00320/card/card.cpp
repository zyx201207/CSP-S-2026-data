#include<bits/stdc++.h>
#define int long long
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Fro(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],cnt,sum[N],val[N],ans[N],f[N];
bitset<N> del;
priority_queue<int> q;
vector<int> pos[N];
bool check1(){
    For(i,1,n-1) if(a[i]>a[i+1]) return false;
    return true;
}
bool check2(){
    int cnt=0;
    For(i,1,n) cnt+=a[i]!=a[i+1];
    return cnt<n;
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    For(i,1,n){
        cin>>a[i];
    }
    if(m==1){
        cout<<n;
        return 0;
    }
    if(m==2){
        if(a[n]==1){
            int ans=0;
            For(i,1,n) ans+=a[i]==2;
            cout<<n<<' '<<ans;
        } else {
            int ans=0;
            For(i,1,n) ans+=a[i]==1;
            cout<<ans<<' '<<n;
        }
        return 0;
    }
    if(check1()){
        For(i,1,n) f[a[i]]=i;
        For(i,1,m) cout<<f[i]<<' ';
        return 0;
    }
    if(check2()){
        For(i,1,n){
            if(a[i]==a[i-1]) val[cnt]++;
            else b[++cnt]=a[i],val[cnt]=1;
        }
        For(i,1,cnt) a[i]=b[i];
        n=cnt;
        For(i,1,n){
            For(j,1,m) sum[j]=0,f[j]=0;
            For(j,1,n) del[j]=0;
            For(j,i,n){
                if(sum[a[j]]){
                    For(k,f[a[j]],j-1){
                        if(!del[k]) sum[a[k]]--,del[k]=1;
                        if(f[a[k]]==k) f[a[k]]=0;
                    }
                    f[a[j]]=j;
                }
                if(!f[a[j]]) f[a[j]]=j;
                sum[a[j]]++;
            }
            For(j,1,m) if(sum[j]) ans[j]+=val[i];
        }
        For(i,1,m) cout<<ans[i]<<' ';
        return 0;
    }
    For(i,1,n){
        For(j,1,m) sum[j]=0,f[j]=0;
        if(n<N/64) For(j,1,n) del[j]=0;
        else del.reset();
        For(j,i,n){
            if(sum[a[j]]){
                For(k,f[a[j]],j-1){
                    if(!del[k]) sum[a[k]]--,del[k]=1;
                    if(f[a[k]]==k) f[a[k]]=0;
                }
                f[a[j]]=j;
            }
            if(!f[a[j]]) f[a[j]]=j;
            sum[a[j]]++;
        }
        For(j,1,m) if(sum[j]) ans[j]++;
    }
    For(i,1,m) cout<<ans[i]<<' ';
    return 0;
}