#include <bits/stdc++.h>
using namespace std;
int dis[15][15];
vector<int> g[15];
bitset<15> choosed,vis;
int n,k;
void dfs(int x){
    for(int y:g[x]){
        if(vis[y]||(!choosed.test(y)))continue;
        vis[y]=true;
        dfs(y);
    }
}
int res;
void choose(int stp,int lst){
    if(stp==k){
        vis.reset();
        int cc=0;
        for(int i=1;i<=n;i++){
            if((!vis[i])&&choosed.test(i)){
                cc++;
                if(cc>2)return;
                dfs(i);
            }
        }
        //cout<<"{";
        //for(int i=1;i<=n;i++)if(choosed.test(i))cout<<i<<',';
        //cout<<"}\n";
        int ans=0;
        for(int i=1;i<=n;i++){
            //cout<<"spot "<<i<<":";
            int tans=n+3;
            for(int j=1;j<=n;j++){
                if(!choosed.test(j))continue;
                tans=min(tans,dis[i][j]);
            }
            //cout<<tans<<'\n';
            ans=max(ans,tans);
        }
        res=min(res,ans);
    }
    for(int i=lst+1;i<=n;i++){
        choosed.set(i);
        choose(stp+1,i);
        choosed.set(i,0);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        res=n+1;
        memset(dis,0x3f,sizeof dis);
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
            dis[u][v]=1;
            dis[v][u]=1;
        }
        for(int i=1;i<=n;i++)dis[i][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                    dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
                    dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
                }
            }
        }
        choose(0,0);
        cout<<res<<'\n';
    }
    return 0;
}
/*
A very good big_sample helper checker.cpp:

#include <bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Input problem name: "<<flush;
    string name;
    cin>>name;
    cout<<"Input sample count: "<<flush;
    int n;
    cin>>n;
    system("unalias g++");
    system("alias g++='g++ -O2 -std=c++14 -static -Wall -Wextra'");
    cout<<"================================================================\n";
    cout<<"\033[38;2;63;191;255mCompiling...\033[0m\n";
    if(system(("g++ "+name+".cpp -o "+name).c_str())){
        cout<<"\033[38;2;191;191;0mCompile error!\033[0m\n";
        return 0xCE;
    }
    for(int i=1;i<=n;i++){
        bool fnf=false;
        if(system(("diff "+name+to_string(i)+".in "+name+to_string(i)+".in").c_str())){
            cout<<"\033[38;2;191;63;63mFile not found: "<<name<<to_string(i)<<".in\033[0m\n";
            fnf=true;
        }
        if(system(("diff "+name+to_string(i)+".ans "+name+to_string(i)+".ans").c_str())){
            cout<<"\033[38;2;191;63;63mFile not found: "<<name<<to_string(i)<<".ans\033[0m\n";
            fnf=true;
        }
        if(!fnf){
            cout<<"\033[38;2;31;127;191mRunning on test case "<<i<<"...\033[0m\n";
            if(system(("./"+name+" < "+name+to_string(i)+".in > "+name+to_string(i)+".out").c_str())){
                cout<<"\033[38;2;191;63;255mRuntime Error on test case "<<i<<"\033[0m\n";
                return 64+i;
            }
            if(system(("diff -BZ "+name+to_string(i)+".out "+name+to_string(i)+".ans").c_str())){
                cout<<"\033[38;2;255;63;63mWrong Answer on test case "<<i<<"\033[0m\n";
                return 128+i;
            }
            cout<<"\033[38;2;0;255;0mAccepted on test case "<<i<<"\033[0m\n";
        }
    }
    cout<<"\033[38;2;0;191;191mAccepted on problem "<<name<<"!\033[0m\n";
    return 0;
}

*/