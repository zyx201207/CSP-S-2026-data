#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q;
vector<int> w;
vector< vector<pair<int,int> > > e;
//int a[505][505],t[505][505];
int dfs(int fr,int to)
{
    if(fr==to) return 0;
    for(int i=0;i<e[fr].size();i++){
        if(dfs(e[fr][i].first,to)!=-1){
            return e[fr][to].second+dfs(e[fr][i].first,to);
        }
    }
    return -1;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    //for(int T=0;T<25;T++){
        cin>>c>>n>>m>>d>>q;
        w.resize(m+1,0);
        bool f1=true,f2=true,f3=true;
        for(int i=1;i<=m;i++) cin>>w[i];

        e.resize(n+m+1);
        int b=m+1;
        vector< vector<long long> > f(n+m+1);
        for(int i=0;i<=m+n;i++){
            f[i].resize(n+m+1,INT_MAX);
        }
        for(int i=1;i<=m+n;i++){
            f[i][i]=0;
        }
        int t1;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            //cout<<x<<endl;
            for(int j=1;j<=x;j++){
                int a,t;
                cin>>a>>t;

                //f[b][a]=t;
                //f[a][b]=t;
                e[b].push_back({a,t});
                e[a].push_back({b,t});
            }
            //cout<<"ok"<<i<<endl;
            b++;
        }
        /*for(int i=1;i<=n+m;i++){
            for(int j=1;j<=n+m;j++) cout<<f[i][j]<<" ";
            cout<<endl;
        }*/
        //cout<<"y1"<<endl;
        //for(int l=1;l<=n+m;l++){
        f1==true;
        /*if(f2){
            for(int i=0;i<q;i++){
                int fr,to;
                queue<pair<int,int>> q;
                q.push({fr,0});
                while(!q.empty()){
                    for(int i=0;i<e[q.front().first].size();i++){

                    }
                }
            }


            return 0;
        }else if(f1){*/
            cout<<1<<endl;
            for(int i=0;i<q;i++){
                int fr,to;
                cout<<dfs(fr,to)+w[fr]+w[to]<<endl;
            }

        /*
        for(int i=1;i<=n+m;i++){
            for(int j=1;j<=n+m;j++){
                //cout<<"j:"<<j<<endl;
                for(int k=1;k<=m+n;k++){
                    if(f[i][j]>f[i][k]+f[k][j]) f[i][j]=f[i][k]+f[k][j];
                    //cout<<i<<" "<<j<<" "<<k<<endl;
                }
            }
        }



        //}
/*
        for(int i=1;i<=n+m;i++){
            for(int j=1;j<=n+m;j++) cout<<f[i][j]<<" ";
            cout<<endl;
        }*/
        //cout<<"ok"<<endl;
        //for(int i=1;i<=m;i++) cout<<w[i]<<" ";
        //cout<<endl<<endl;
/*
        for(int i=0;i<q;i++){
            int fr,to;
            //cin>>fr>>to;
            //cout<<fr<<" "<<to<<" "<<f[fr][to]<<" "<<w[fr]<<" "<<w[to]<<endl;
            cout<<f[fr][to]+w[fr]+w[to]<<endl;
        }
    //}
    */

    return 0;
}
