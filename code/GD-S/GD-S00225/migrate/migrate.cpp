#include<bits/stdc++.h>
#define N 2000006
using namespace std;
int c,t;
int n;
long long d;
long long x[N];
long long res;
int to[N];
int rto[N];
void init(){
    for(int i=1;i<=n;i++){
        to[i]=to[i-1];
        to[i]=max(to[i],i);
        while(to[i]<n&&x[to[i]+1]-x[i]<=d)to[i]++;
    }
    rto[n+1]=n+1;
    for(int i=n;i>=1;i--){
        rto[i]=rto[i+1];
        rto[i]=min(rto[i],i);
        while(rto[i]>1&&x[i]-x[rto[i]-1]<=d)rto[i]--;
    }
}
bool check(int u,int v){
    if(x[v]-x[u]<=d)return false;
    vector<int>v1;
    int cur=u;
    v1.push_back(u);
    while(cur<v){
        cur=min(v,to[cur]);
        v1.push_back(cur);
    }
    vector<int>v2;
    cur=v;
    v2.push_back(v);
    while(cur>u){
        cur=max(u,rto[cur]);
        v2.push_back(cur);
    }
    reverse(v2.begin(),v2.end());
    int l=v1.size();
    int cnt=0;
    for(int i=0;i<l;i++){
        if(v1[i]!=v2[i]){
            if(abs(v1[i]-v2[i])>1){
                return false;
            }
            cnt++;
        }
    }
    return cnt==1;
}
void bbff(){
    res=0;
    long long dd=d/(x[2]-x[1]);
    for(int len=1;len<n;len++){
        if(len<=dd)continue;
        long long cont=0;
        if(len==2*dd-1){
            cont=1;
        }
        res+=n-len;
    }
    cout<<res<<"\n";
}
void work(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    if(c==11||c==12){
        bbff();
        return;
    }
    res=0;
    init();
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            bool tmp=check(i,j);
            res+=tmp;
            if(j<n&&x[j+1]-x[j]>d)break;
        }
    }
    cout<<res<<"\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)work();
}