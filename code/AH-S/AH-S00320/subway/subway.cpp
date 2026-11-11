#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,q,s,d;
int st,ed;
int p[N],a[N],t[N];
int f[N],c[N][505];
struct edge{
    int next,w;
};
vector<edge> g[N];
struct node{
  int x,id;
};
void bfs(int st){
    memset(f,-1,sizeof(f));
    queue<node> q;
    f[st]=0;
    q.push((node){st,0});
    while(!q.empty()){
        node h=q.front(); q.pop();
        int u=h.x,idx=h.id;
        /*cout<<"after "<<u<<" is ";
        if(q.empty()){
            cout<<" not";
        }else{
            cout<<q.front().x;
        }
        cout<<".\n";
        */
        for(edge e:g[u]){
            int v=e.next;
            //cout<<u<<":"<<v<<" "<<idx<<"\n";
            if(c[idx][v]){//then the idx
                //cout<<"t1 : "<<u<<"->"<<v<<"\n";
                //cout<<f[u]<<" + "<<c[idx][v]<<"   "<<f[u]+c[idx][v]<<"\n";
                if(v==ed&&(f[v]==-1||f[u]+c[idx][v]<f[v])){
                    //cout<<"t0 : "<<v<<"\n";
                    f[v]=f[u]+c[idx][v];
                    q.push(node{v,idx});
                }else if(f[v]==-1||f[u]<f[v]){
                    f[v]=f[u];
                    q.push(node{v,idx});
                }
                continue;
            }
            if(idx==0){//start new idx
                for(int i=1;i<=n;i++){
                    if(c[i][u]&&c[i][v]){
                        idx=i;
                        break;
                    }
                }
                //cout<<"t2 : "<<u<<"->"<<v<<" of"<<idx<<"\n";
                if(v==ed&&(f[v]==-1||f[u]+c[idx][u]+c[idx][v]<f[v])){
                    f[v]=f[u]+c[idx][u]+c[idx][v];
                    q.push(node{v,idx});
                }else if(f[v]==-1||f[u]+c[idx][u]<f[v]){
                    f[v]=f[u]+c[idx][u];
                    q.push(node{v,idx});
                }
                continue;
            }
            bool flag=false;
            for(int i=1;i<=n;i++){
                if(c[i][u]&&c[i][v]){
                    //cout<<"t3 : "<<u<<"->"<<v<<"\n";
                    flag=true;
                    f[u]+=c[idx][u];
                    //cout<<f[u]<<" + "<<c[i][u]<<" = "<<f[u]+c[idx][u]+c[i][u]<<"    "<<f[v]<<"\n";
                    if(v==ed&&(f[v]==-1||f[u]+c[idx][u]+c[i][u]+c[i][v]<f[v])){
                        //cout<<"t31\n";
                        f[v]=f[u]+c[i][u]+c[i][v];
                        idx=i;
                        q.push((node){v,idx});
                    }else if(f[v]==-1||f[u]+c[idx][u]+c[i][u]<f[v]){
                        f[v]=f[u]+c[i][u];
                        idx=i;
                        //cout<<"t32 : "<<v<<"\n";
                        q.push((node){v,idx});
                    }
                    break;
                }
            }
            if(!flag&&(f[v]==-1||f[u]+e.w+c[idx][u]<f[v])){//end the idx
                //cout<<"t4 : "<<u<<"->"<<v<<"\n";
                f[u]+=c[idx][u];
                f[v]=f[u]+e.w;
                q.push((node){v,0});
            }
        }
    }
    return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>s>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>p[i];
    }
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[j]>>t[j];
            c[i][a[j]]=t[j];
            if(j>1){
                g[a[j-1]].push_back((edge){a[j],t[j-1]+t[j]});
            }
        }
    }
    /*
    for(int i=1;i<=m;i++){
        cout<<i<<":";
        for(edge e:g[i]){
            cout<<e.next<<" ";
        }
        cout<<"\n";
    }
    */
    while(q--){
        cin>>st>>ed;
        int tmp=p[st]+p[ed];
        //cout<<tmp<<" ";
        bfs(st);
        //cout<<f[ed]<<" ";
        tmp+=f[ed];
        cout<<tmp<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 1
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
*/
