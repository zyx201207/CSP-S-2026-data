#include <bits/stdc++.h>
using namespace std;
int a[305],d[305],anta[500005];
pair<int,int> dfs(int nw,int y,int n,int stp,int d){
    if(nw==y) return {stp,1};
    int nmin=1e9,nmincnt=0;
    for(int i=nw+1;i<=y;i++){
        if(a[i]-a[nw]<=d){
            auto[nw,k]=dfs(i,y,n,stp+1,d);
            if(nw<nmin){
                nmin=nw;
                nmincnt=k;
            }else if(nw==nmin){
                nmincnt+=k;
            }
        }
    }
    return {nmin,nmincnt};
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t1,t2;
    cin>>t1>>t2;
    while(t2--){
        memset(a,0,sizeof a);
        int n,d;
        cin>>n>>d;
        if(n>300){
            for(int i=1;i<=n;i++){
                cin>>anta[i];
            }
            cout<<0<<'\n';
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(i==j) continue;
                auto[nmin,nmincnt]=dfs(i,j,n,1,d);
                if(nmincnt==2){
                    cnt++;
                }
            }
        }

        cout<<cnt<<'\n';
    }
}
//14:45 first try 17:53 baoli 8pts
