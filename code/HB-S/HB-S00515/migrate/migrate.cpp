#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=5e3+5;
long long a[N];
long long dis[N][N];
long long cnt[N][N];
vector<int> G[N];
int vis[N];

void clr(int n){
    for(int i=1;i<=n;i++){
        G[i].clear();
        vis[i]=0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            int n;
            cin>>n;
            long long d;
            cin>>d;
            long long x,y;
            for(int i=1;i<n;i++){
                cin>>x;
            }
            cin>>y;
            long long cha=y-x;
            long long maxx=d/cha;

            if(maxx>=n-1||!maxx){
                cout<<0<<'\n';
                continue;
            }
            //cout<<maxx<<'\n';

            long long res=0;
            for(int i=1;i<=n;i++){
                //cout<<i<<'\n';
                long long z=(n-i)/maxx;
                //cout<<z<<'\n';
                if((n-i)%maxx!=0){
                    res+=z+1;
                }
            }
            cout<<res<<'\n';

        }
    }
    else{
        while(t--){
            int n;
            cin>>n;
            long long d;
            cin>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    if(a[j]-a[i]<=d){
                        //cout<<i<<" "<<j<<'\n';
                        G[i].push_back(j);
                    }
                    dis[i][j]=0;
                    cnt[i][j]=0;
                }
            }
            for(int i=1;i<n;i++){//start
                int num=0;
                /*
                for(int j=i;j<=n;j++){//topo
                    num++;
                    cout<<num<<'\n';
                    for(int y:G[j]){
                        cout<<"i: "<<i<<" "<<"y: "<<y<<" "<<dis[i][y]<<" "<<num<<'\n';
                        if(num==dis[i][y]){
                            cnt[i][y]++;
                        }
                        else if(!dis[i][y]||dis[i][y]>num){
                            dis[i][y]=num;
                            cnt[i][y]=0;
                        }

                    }
                }
                */
                queue<int> q;
                q.push(i);
                vis[i]=i;
                cnt[i][i]=1;
                while(!q.empty()){//n
                    int len=q.size();
                    num++;
                    for(int k=1;k<=len;k++){
                        int u=q.front();
                        q.pop();
                        for(int v:G[u]){
                            if(num==dis[i][v]){
                                cnt[i][v]+=cnt[i][u];
                            }
                            else if(!dis[i][v]||dis[i][v]>num){
                                dis[i][v]=num;
                                cnt[i][v]=cnt[i][u];
                            }
                            if(vis[v]!=i){
                                q.push(v);
                                vis[v]=i;
                            }
                        }
                    }

                }
            }
            long long res=0;
            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    //cout<<"cnt: "<<cnt[i][j]<<'\n';
                    if(cnt[i][j]==2){
                        //cout<<"*******"<<i<<" "<<j<<'\n';
                        res++;
                    }
                }
            }
            cout<<res<<'\n';
            clr(n);
        }
    }
    return 0;
}
/*
11 1
10 22
0 7 14 21 28 35 42 49 56 63
*/