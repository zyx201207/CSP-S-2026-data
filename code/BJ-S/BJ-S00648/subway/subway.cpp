#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,a[500005]={},t[500005]={},x,y;
int w[500005]={};
int flag[10500005]={};
struct node{
    int id,v;
};
vector<node> s[10500005];
int find(int be,int en,int sum){
    if(be==en) return sum;
    int ans = INT_MAX;
    flag[be] = sum;
    for(int i = 0;i < s[be].size();i++){
        node nex = s[be][i];
        if(flag[nex.id]!=0&&sum+nex.v>=flag[nex.id]) continue;
        ans = min(ans,find(nex.id,en,sum+nex.v));
    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= m;i++){
        cin>>w[i];
    }
    for(int i = 1;i <= n;i++){
        cin>>k;
        if(k==1) continue;
        for(int j = 1;j <= k;j++){
            cin>>a[j]>>t[j];
            s[a[j]].push_back(node{a[j]+i*m,t[j]});
            s[a[j]+i*m].push_back(node{a[j],t[j]});
            if(j>1){
                s[a[j]+i*m].push_back(node{a[j-1]+i*m,0});
                s[a[j-1]+i*m].push_back(node{a[j]+i*m,0});
            }
        }
    }
    for(int i = 1;i <= q;i++){
        cin>>x>>y;
        cout<<w[x]+w[y]+find(x,y,0)<<endl;
        memset(flag,0,sizeof(flag));
    }
}
