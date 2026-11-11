#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx=16355;
ll s[mx][mx];
int num;
void floyd(){
    for(int k=1;k<=num;++k){
        for(int i=1;i<=num;++i){
            if(i==k) continue;
            for(int j=1;j<=num;++j){
                if(j==i||j==k) continue;
                if(s[i][k]!=-1&&s[k][j]!=-1){
                    if(s[i][k]+s[k][j]<s[i][j]){
                        s[i][j]=s[i][k]+s[k][j]+1;
                    }
                }
            }
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t>0){
        t--;
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=k;i++) s[i][i]=0;
        for(int i=1;i<k;i++){
            for(int j=i+1;j<=k;j++){
                s[i][j]=s[j][i]=-1;
            }
        }
        for(int i=1;i<=n;i++){
            int u,v;
            cin>>u>>v;
            s[u][v]=s[v][u]=1;
        }
        floyd();
        ll ans=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,s[i][j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
