#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,k;
vector<int>a[N];
int col[N];
pair<int,int>ht[N];
inline void cmax(pair<int,int>&x,int y){
    if(x.first<y){
        x.second=x.first;
        x.first=y;
    }else if(x.second<y){
        x.second=y;
    }
}
void dfs_node(int x,int f){
    ht[x]={0,0};
    for(auto i:a[x]){
        if(i!=f&&(col[i]==0||col[i]==col[x])){
            col[i]=col[x];
            dfs_node(i,x);
            cmax(ht[x],ht[i].first+1);
        }
    }
}
int len[N];
void dfs_len(int x,int f,int hi_len){
    len[x]=max(hi_len,ht[x].first);
    for(auto i:a[x]){
        if(i!=f&&(col[i]==0||col[i]==col[x])){
            dfs_len(i,x,max(hi_len,ht[x].first==ht[i].first+1?ht[x].second:ht[x].first)+1);
        }
    }
}
int dfs_calc(int x,int f,int s){
    int ans=0;
    for(auto i:a[x]){
        if(i!=f&&(col[i]==0||col[i]==col[x])){
            ans+=dfs_calc(i,x,s);
        }
    }
    return ans+(ht[x].first>=s);
}
inline int solve(int x,int s){
    dfs_node(x,0);
    dfs_len(x,0,0);
    int sum=0x3f3f3f3f,root=0;
    for(int i=1;i<=n;i++){
        if(col[i]==col[x]){
            if(sum>len[i]){
                root=i;
                sum=len[i];
            }
        }
    }
    dfs_node(root,0);
    return max(1,dfs_calc(root,0,s));
}
inline bool check(int s){
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        for(auto j:a[i]){
            for(int k=1;k<=n;k++){
                col[k]=0;
            }
            col[i]=1;
            col[j]=2;
            int v1=solve(i,s),v2=solve(j,s);
//            cerr<<i<<' '<<j<<' '<<v1<<' '<<v2<<'\n';
            ans=min(ans,v1+v2);
        }
    }
//    cerr<<s<<' '<<ans<<'\n';
    return ans<=k;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int C,T;
    cin>>C>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            a[i].clear();
        }
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        int l=0,r=n;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        cout<<l<<'\n';
    }
    return 0;
}