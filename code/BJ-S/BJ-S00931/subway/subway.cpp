#include <bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=505;
int c,n,m,d,q;
int w[M],k[N];
vector<int> a[M],t[M];
int dfs(int finish,int sta,int pos,int sub,int time){
    if(sta==finish){
        if(pos==0) return time;
        else if(pos==1) dfs(finish,sta,0,sub,time+w[sta]);
        else{
            int cnt;
            for(int i=0;i<a[sub].size();i++){
                if(a[sub][i]==sta){
                    cnt=i;
                    break;
                }
            }
            dfs(finish,sta,1,sub,time+t[sub][cnt]);
        }
    }
    if(pos==0) dfs(finish,sta,1,sub,time+w[sta]);
    if(pos==1){
        int cnt;
        for(int i=0;i<a[sub].size();i++){
            if(a[sub][i]==sta){
                cnt=i;
                break;
            }
        }
        dfs(finish,sta,2,sub,time+t[sub][cnt]);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].size();j++){
            dfs(finish,a[i][j],2,i,time);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];//0->1
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=2*k[i];j++){
            int s;
            cin>>s;
            if(j%2==0) a[i].push_back(s);
            else t[i].push_back(s);//1->2
        }
    }
    while(q--){
        int x,y,ans=1e9;
        cin>>x>>y;
        for(int i=1;i<=n;i++){
            for(int j=0;j<k[i];j++){
                if(a[i][j]==x) ans=min(ans,dfs(y,x,0,i,0));
            }
        }
        cout<<ans<<endl;
    }
}