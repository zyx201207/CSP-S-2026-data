#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
vector<int> pos[300010];
int lp[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]].push_back(i);
        lp[a[i]]=i;
    }
    for(int i=1;i<=m;i++){
        int ans=lp[i];
        int mx=0;
        for(int j=1;j<=m;j++){
            if(j==i) continue;
            int f;
            int l;
            for(int k=0;k<pos[j].size();k++){
                if(pos[j][k]<lp[i]) f=pos[j][k];
                                if(pos[j][k]>lp[i]) l=pos[j][k];
            }
            if(l!=pos[j].size()) mx=max(mx,f);
        }
        cout<<ans-mx<<" ";
    }
    return 0;
}
