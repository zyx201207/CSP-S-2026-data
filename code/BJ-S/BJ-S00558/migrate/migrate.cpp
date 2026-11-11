#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[2000060],ans;
struct st{
    int x,num;
};

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n<=300){
            vector<int> to[350];
            for(int i=1;i<=n;i++){
                for(int j=i+1;a[i]+d>=a[j]&&j<=n;j++){
                    to[i].push_back(j);
                }
            }
            for(int i=1;i<=n;i++){
                queue<st> q;
                int cnt[350]={},minn[350]={};
                q.push({i,0});
                while(!q.empty()){
                    int x=q.front().x;
                    int num=q.front().num;
                    q.pop();
                    if(minn[x]==0){
                        minn[x]=num;
                        cnt[x]=1;
                    }else if(minn[x]<num){
                        continue;
                    }else if(minn[x]==num){
                        cnt[x]++;
                    }else{
                        minn[x]=num;
                        cnt[x]=1;
                    }
                 //   cout<<x<<" "<<num<<" "<<cnt[x]<<endl;
                    for(int nd : to[x]) q.push({nd,num+1});
                }

                for(int j=i+1;j<=n;j++){
                    if(cnt[j]==2) ans++;
                    //if(cnt[j]==2) cout<<j<<endl;
                }
                //cout<<i<<" "<<ans<<endl;
            }
            cout<<ans<<'\n';
           // cout<<endl;
        }
    }
    return 0;
}
