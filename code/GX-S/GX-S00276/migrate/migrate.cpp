#include<bits/stdc++.h>
using namespace std;

int cnt;
void dfs(int pos,int d,int ch,int ne,int r,vector<int>&s,int last){
    if(ch==ne){
        if(s[r]-s[last]<=d){
            cnt++;
            return ;
        }
    }

    if(s[pos+1]-s[pos]>d) return ;
    dfs(pos+1,d,ch+1,ne,r,s,pos);

    if(s[pos+1]-s[last]>d) return ;
    dfs(pos+1,d,ch,ne,r,s,last);
}

void solve(){
    int ans=0;
    int n,d;cin>>n>>d;
    vector<int>s(n+1);
    for(int i=1;i<=n;i++) cin>>s[i];

    for(int l=1;l<=n-3;l++){
        for(int r=l+3;r<=n;r++){
            int maxx=r-l-2;
            for(int i=1;i<=maxx;i++){
                cnt=0;
                dfs(l+1,d,0,i,r,s,l);
                if(cnt>0 and cnt<2) break;
                if(cnt>=2){
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
