#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define ffor(i,a,b) for(ll i=(a);i<=(b);++i)
#define roff(i,a,b) for(ll i=(a);i>=(b);--i)
const ll N=200010;
ll n,m,aans,a[N],k[N],cnt[100];
// ll b[N],tvst[N],vst[N];
vector<ll> x[N];
bool cmp(ll a,ll b){
    return a>b;
}
// void print(){
//     ll ans=-1;
//     ffor(i,1,n){
//         if(vst[i]||tvst[i]) continue;
//         if(ans==-1) ans=a[i];
//         else ans&=a[i];
//     }
//     cout<<ans;
// }
void prnt(){
    ll ans=-1;
    ffor(i,1,n){
        if(!k[i]) continue;
        if(ans==-1) ans=a[i];
        else ans&=a[i];
        // cout<<a[i]<<" ";
    }
    // cout<<"\n";
    aans=max(ans,aans);
}
void dfs(ll x,ll c){
    if(x==n+1){
        if(c==m) prnt();
        return;
    }
    if(c>m) return;
    k[x]=0;
    dfs(x+1,c);
    k[x]=1;
    dfs(x+1,c+1);
}
// void sol(){
//     ll ans=-1;
//     c=0;
//     ffor(i,1,n){
//         if(vst[i]) continue;
//         b[++c]=a[i];
//     }
//     dfs(1,0);
//     cout<<aans;
// }
// void solveBF(){
//     ll pos=-1,s=n;
//     roff(i,30,0) if(cnt[i]>=m){
//         pos=i;
//         break;
//     }
        // cout<<pos<<"\n";
//     while(s>m){
//         ffor(i,1,n) if(x[i][pos]==0) tvst[i]=1,s--;
            // ffor(i,1,n) if(!tvst[i]) cout<<a[i]<<" ";
            // cout<<"\n";
//         if(s==m){
//             print();
//             return;
//         }else if(s<m){
//             sol();
//             return;
//         }
//         ffor(i,1,n) vst[i]=tvst[i]||vst[i],tvst[i]=0;
//         pos--;
//     }
// }
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    ffor(i,1,n) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[1];
    }else if(m==n){
        ll ans=a[1];
        ffor(i,2,n) ans&=a[i];
        cout<<ans;
    }else if(m==2){
        ll ans=0;
        ffor(i,1,n) ffor(j,i+1,n){
            ans=max(ans,a[i]&a[j]);
        }
        cout<<ans;
    }else if(n<=20){
        dfs(1,0);
        cout<<aans;
    }else{
        ffor(i,1,n){
            ll t=a[i];
            while(t!=0){
                x[i].push_back(t%2);
                t/=2;
            }
        }
        ffor(i,1,n){
            ll cc=0;
            for(auto t:x[i]) cnt[cc++]++;
        }
        ll t1=1,t2=1;
        ffor(i,1,n){
            if(a[i]!=n-i) t2=0;
            for(auto t:x[i]) if(t==0) t1=0;
        }
        if(t1||t2){
            ll ans=a[1];
            ffor(i,2,m) ans&=a[i];
            cout<<ans;
        }else{
            dfs(1,0);
            cout<<aans;
        }
    }
    return 0;
}
