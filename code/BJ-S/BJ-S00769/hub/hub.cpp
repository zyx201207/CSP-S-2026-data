#include<bits/stdc++.h>
using namespace std;
long long c,T,n,k,ans;
long long dep[1000005];
vector<long long> e[1000005];
bool check(long long x){
    long long cnt=0;
    queue<long long> q;
    q.push(1);
    dep[1]=1;
    while(!q.empty()){
        long long u=q.front();
        q.pop();
        for(int i=0;i<e[u].size();i++){
            long long v=e[u][i];
            if(dep[v]!=0)
                continue;
            dep[v]=dep[u]+1;
            if((dep[v]-1)%(2*x)==x){
                cnt++;
            }
            q.push(v);
        }
    }
    if(cnt<=k)
        return true;
    return false;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            long long u,v;
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            dep[i]=0;
        }
        if(n==k){
            cout<<0<<"\n";
        }
        long long l=1,r=n;
        while(l<=r){
            long long mid=(l+r)/2;
            for(int i=1;i<=n;i++){
                dep[i]=0;
            }
            if(check(mid)){
                r=mid-1;
                ans=mid;
            }else{
                l=mid+1;
            }
        }
        cout<<ans;
    }

    return 0;
}
