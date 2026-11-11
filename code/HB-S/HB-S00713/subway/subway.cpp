#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500050],b[500050],e[500][1000],best[500050],sss[1000];
int a[500][200005];
int flag[100050];
vector<int> h[500050];
queue<int> p;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>sss[i];
        for(int j=1;j<=sss[i];j++){
            cin>>a[i][j];
            cin>>e[a[i][j]][i];
            h[a[i][j]].push_back(i);
        }
    }
    if(c<=8){
        while(q--){
        for(int i=1;i<=m;i++) best[i]=1e16;
        int from,dest; cin>>from>>dest;
        long long ans=w[from]+w[dest];
        best[from]=0; p.push(from);
        //for(int i=1;i<=n;i++) flag[i]=0;
        while(p.size()){
            int ss=p.front();  p.pop();
            for(int i=0;i<h[ss].size();i++){
        //        if(flag[h[ss][i]]) continue;
        //        flag[h[ss][i]]=1;
                for(int j=1;j<=sss[h[ss][i]];j++){
                    int a1=a[h[ss][i]][j];
                    long long kkk=best[ss]+e[ss][h[ss][i]]+e[a1][h[ss][i]];
                    if(kkk<best[a1]){
                        best[a1]=kkk; p.push(a1);
                    }
                }
            }
        }
        cout<<ans+best[dest]<<endl;
        while(p.size()) p.pop();
    }
    }
    else{
        while(q--){
        for(int i=1;i<=m;i++) best[i]=1e16;
        int from,dest; cin>>from>>dest;
        long long ans=w[from]+w[dest];
        best[from]=0; p.push(from);
        for(int i=1;i<=n;i++) flag[i]=0;
        while(p.size()){
            int ss=p.front();  p.pop();
            for(int i=0;i<h[ss].size();i++){
                if(flag[h[ss][i]]) continue;
                flag[h[ss][i]]=1;
                for(int j=1;j<=sss[h[ss][i]];j++){
                    int a1=a[h[ss][i]][j];
                    long long kkk=best[ss]+e[ss][h[ss][i]]+e[a1][h[ss][i]];
                    if(kkk<best[a1]){
                        best[a1]=kkk; p.push(a1);
                    }
                }
            }
        }
        cout<<ans+best[dest]<<endl;
        while(p.size()) p.pop();
        }
    }
    return 0;
}
