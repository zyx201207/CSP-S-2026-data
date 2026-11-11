#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],tim,st[200005],up,sum,ans,q[200005];
vector<int> cnt[35];
bool f[200005],fir;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int mask=31;mask>=0;mask--){
        for(int i=1;i<=n;i++){
            if((a[i]>>mask)&1) cnt[mask].push_back(i);
        }
    }
    for(int mask=31;mask>=0;mask--){
        tim++;
        if(cnt[mask].size()>=m&&fir==0){
            for(int i=0;i<cnt[mask].size();i++) f[cnt[mask][i]]=1,st[++up]=cnt[mask][i];
            sum=up;
            fir=1;
        }else if(cnt[mask].size()>=m){
            for(int i=0;i<cnt[mask].size();i++)
                if(f[cnt[mask][i]]==1) q[cnt[mask][i]]=tim;
            int res=0;
            for(int i=1;i<=up;i++){
                if(st[i]!=0){
                    if(q[st[i]]!=tim) res++;
                }
            }
            if(sum-res<m) continue;
            sum-=res;
            for(int i=1;i<=up;i++){
                if(st[i]!=0){
                    if(q[st[i]]!=tim) st[i]=0;
                }
            }
        }
    }
    for(int i=1;i<=up;i++){
        if(st[i]!=0){
            ans=a[st[i]];
            break;
        }
    }
    for(int i=1;i<=up;i++){
        if(st[i]!=0){
            ans&=a[st[i]];
        }
    }
    cout<<ans;
    return 0;
}
