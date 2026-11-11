#include<bits/stdc++.h>
using namespace std;
long c,t;
long n,d;
long x[2000005];
bool check(long a,long b){
    if(a==b || a+1==b || a>b) return false;
    stack<pair<long,long>> q;
    q.push({a,0});
    long mina=INT_MAX;
    long cnt=0;
    while(!q.empty()){
        pair<long,long> now=q.top();
        q.pop();
        if(now.second>mina) continue;
        if(now.first==b){
            if(now.second<mina){
                mina=now.second;
                cnt=1;
            }else if(now.second==mina){
                cnt++;
            }
            continue;
        }
        for(long i=now.first+1;i<n;i++){
            if(x[i]-x[now.first]>d) break;
            q.push({i,now.second+1});
        }

    }
    if(cnt==2) return true;
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(long i=0;i<n;i++){
            cin>>x[i];
        }
        long ans=0;
        for(long i=0;i<n;i++){
            for(long j=i+1;j<n;j++){
                if(check(i,j)) ans++;
            }
        }
        cout<<ans<<endl;
    }
}
