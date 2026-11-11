#include<bits/stdc++.h>
using namespace std;
long long n,m,mx,a[200010],dcnt[40];
vector<long long> dcnta[40];
bool vis[40];
void dfs(long long k){
    long long i=k;
    for(;i>=0;i--){
        if(dcnt[i]>=m){
            vis[i]=true;
            break;
        }
    }
    if(i==-1){
        return;
    }
    memset(dcnt,0,sizeof(dcnt));
    for(long long j=0;j<=mx;j++){
        if(j!=i){
            dcnta[j].clear();
        }
    }
    for(long long j=0;j<dcnta[i].size();j++){
        long long t=dcnta[i][j];
        long long tk=0;
        while(t){
            if((t&1)&&tk!=i){
                dcnt[tk]++;
                dcnta[tk].push_back(dcnta[i][j]);
            }
            t>>=1;
            tk++;
        }
    }
    dfs(i-1);
    return;
}
long long mypow(long long x,long long k){
    long long ans=1;
    while(k--){
        ans*=2;
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        long long t=a[i],k=0;
        while(t){
            if(t&1){
                dcnt[k]++;
                dcnta[k].push_back(a[i]);
                mx=max(mx,k);
            }
            t>>=1;
            k++;
        }
    }
    dfs(mx);
    long long ans=0;
    for(long long i=0;i<=mx;i++){
        if(vis[i]){
            ans+=(mypow(2,i));
        }
    }
    cout<<ans;
    return 0;
}
