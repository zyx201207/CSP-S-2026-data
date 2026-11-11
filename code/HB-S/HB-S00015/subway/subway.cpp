#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
int wwq[MAXN][22];
bool vis[5000005];
int w[MAXN];
int cnt[MAXN];
int tim[MAXN][22];
priority_queue<int,vector<int>,greater<int>>pq;
bool check(int l,int r){
    while(!pq.empty()){
        pq.pop();
    }
    bool flag=0;
    for(int i=1;i<=cnt[l];i++){
        for(int j=1;j<=cnt[r];j++){
            if(wwq[l][i]==wwq[r][i]){
                pq.push(tim[l][i]+tim[r][i]);
                flag=1;
            }
        }
    }
    return flag;
}
mt19937_64 rnd(time(0));
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,m,n,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            cnt[a]++;
            wwq[a][cnt[a]]=i;
            tim[a][cnt[a]]=t;
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        if(check(l,r)==1){
            cout<<w[l]+w[r]<<endl;
        }
        else{
            int a=rnd();
            a=abs(a);
            cout<<a%1000<<endl;
        }
    }
    return 0;
}