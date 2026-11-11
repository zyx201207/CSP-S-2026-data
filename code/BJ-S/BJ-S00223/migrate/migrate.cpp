#include<bits/stdc++.h>

using namespace std;
const long long INF=1000000000000000000;
int c,t;
vector<pair<int,int> > e[5010];
long long dfs(int l,int r,int step,long long ans,int mod,int tar=0,int ans2=0){
    if(mod==1){
        if(l==r){
            //cout<<'*';
            //cout<<step<<'\n';
            return step;
        }
        for(auto a : e[l]){
            if(a.first<=r){
                ans=min(ans,dfs(a.first,r,step+1,ans,1));
            }else break;
        }
        return ans;
    }else if(mod==2){
        if(l==r){
                //cout<<'*';
            return step;
        }
        for(auto a : e[l]){
            if(a.first<=r){
                if(dfs(a.first,r,step+1,ans,1)==tar)ans2++;
            }else break;
        }
        return ans2;
    }

}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        for(int i=0;i<5010;i++)e[i].clear();
        long long n,d,cnt=0;
        cin>>n>>d;
        long long x[n+10],cf[n+10][n+10];
        cf[0][0]=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                cf[i][j]=x[j]-x[i];
            }
        }
        for(int u=1;u<=n;u++){
            for(int v=u+1;v<=n;v++){
                if(cf[u][v]<=d){
                    e[u].push_back({v,cf[u][v]});
                    //e[v].push_back({u,cf[u][v]});
                }
            }
        }
        /*for(int i=1;i<=n;i++){
            for(auto j : e[i])cout<<j.first<<' ';
            cout<<'\n';
        }*/
        for(int u=1;u<=n;u++){
            for(int v=u+1;v<=n;v++){
                //if(cf[u][v]>d)continue;
                long long tar=dfs(u,v,0,INF,1);
                //cout<<u<<' '<<v<<' '<<tar<<'\n';
                if(tar==1 || tar==0)continue;
                else{
                    if(dfs(u,v,0,INF,2,tar)==2){
                        cnt++;
                        //cout<<tar<<' '<<cnt<<' '<<u<<' '<<v<<'\n';
                    }
                }
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
