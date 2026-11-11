#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,d,x[N];
vector<int> ans[N];
bool vis[N];
int DFS(int q,int h){
    //cout<<q<<" "<<h<<endl;
    ans[q].push_back(h);
    //cout<<q<<endl;
    for(int i=q+1;i<=n;i++){
        int t=x[i]-x[q];
        if(t<0) t=-t;
        //cout<<i<<" "<<x[q]<<endl;
        if(!vis[i]&&t<=d){
            vis[i]=true;
            DFS(i,h+1);
            vis[i]=false;
        }
    }
    return 0;
}
int main(){
    freopen("migrate.in","r",stdin);                                              
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
        int pri=0;
        for(int j=1;j<=n;j++){
            memset(vis,false,sizeof(vis));
            memset(ans,0,sizeof(ans));
            vis[j]=true;
            DFS(j,1);
            //cout<<endl;
            for(int q=1;q<=n;q++){
                //cout<<q<<" "<<ans[q]<<endl;
                int mi=0x3f3f3f3f,total=0;
                for(auto x:ans[q]){
                    if(x<mi){
                        mi=x;
                    }
                }
                for(auto x:ans[q]){
                    if(x==mi){
                        total++;
                    }
                }
                if(total==2){
                    pri++;
                }
            }
        }
        cout<<pri<<endl;
    }
    return 0;
}