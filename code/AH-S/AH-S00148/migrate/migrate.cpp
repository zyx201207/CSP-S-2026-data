#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int a[N]={};
int c,t;
int n,d;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(d==2){
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    bool f=0;
                    for(int k=i;k<j;k++){
                        if(abs(a[k+1]-a[k])>d){
                            f=1;
                            break;
                        }
                    }
                    if(!f){
                        int len=a[j]-a[i];
                        if(len/d==1 && (j-i)%d==1) ans++;
                    }
                }
            }
            cout<<ans<<'\n';
            continue;
        }
        if(n<=300){
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    if(a[j]-a[i]<=d) continue;
                    map<int,int> m;
                    queue<pair<int,int> > q;
                    q.push({i,0});
                    int in=0x3f3f3f3f;
                    bool used[a[j]+1]={};
                    used[a[i]]=1;
                    while(!q.empty()){
                        pair<int,int> p=q.front();
                        q.pop();
                        if(p.first==j){
                            in=min(in,p.second);
                            m[p.second]++;
                            continue;
                        }
                        for(int k=p.first+1;a[k]<=a[p.first]+d;k++){
                            if(!used[a[k]]){
                                used[a[k]]=1;
                                q.push({k,p.second+1});
                            }
                        }
                    }
                    if(m[in]==2) ans++;
                }
            }
            cout<<ans<<'\n';
        }else cout<<0<<'\n';
    }
    return 0;
}
