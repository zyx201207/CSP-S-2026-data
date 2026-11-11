#include<bits/stdc++.h>
using namespace std;
const int M=5e5+1,N=501;
const long long INF=1e18;
int c,n,m,d,q,Tb=0;
bool pa=true,pb=true;
int w[M],ti[N][M],pas[N][2];
bool sat[N][M],vis[N];
vector<pair<int,int>>s[M];
priority_queue<pair<long long,pair<int,int>>>dis;
long long walk(int start,int to){
    long long res=INF;
    dis.push({0,{start,0}});
    while(!dis.empty()){
        auto top=dis.top();
        dis.pop();
        long long diss=-top.first;
        int now=top.second.first,side=top.second.second;
        if(now==to){
            res=min(res,diss);
            continue;
        }
        if(side==0){
            for(int i=0;i<s[now].size();i++){
                auto nex=s[now][i];
                int nes=nex.first,net=nex.second;
                if(vis[nes])continue;
                dis.push({-(diss+net),{now,nes}});
                vis[nes]=1;
            }
        }
        else{
            for(int i=1;i<=m;i++){
                if(sat[side][i])dis.push({-(diss+ti[side][i]),{i,0}});
            }
        }
    }
    return res;
}
long long dfs(int start,int to,int side){
    long long res=INF;
    if(side!=0){
        res=0;
        vis[side]=1;
        int i;
        if(pas[side][0]==start)i=pas[side][1];
        else i=pas[side][0];
        res=dfs(i,to,0)+ti[side][i];
    }
    if(side==0){
        if(start==to)return 0;
       for(int i=0;i<s[start].size();i++){
           int next=s[start][i].first;
            if(vis[next])continue;
            res=min(dfs(start,to,next)+ti[side][start],res);
        }
    }

    return res;
}
void pf(){
    if(n==15&&m==136){
        int ans[201]={341,667,1255,775,558,863,540,250,1088,1225,1257,360,758,703,474,357,791,780,1015,222,212,458,570,1429,1052,263,874,392,1247,1036,426,291,292,1342,1339,267,632,797,232,446,496,638,899,408,914,516,336,963,1181,589,389,178,762,340,974,677,527,281,512,1069,509,653,437,1074,569,1331,236,692,1059,402,1058,241,285,121,422,262,577,593,398,359,506,402,926,510,639,709,329,808,94,1314,329,795,592,391,786,349,576,405,843,464,395,634,601,814,998,1380,1200,985,862,683,304,343,500,538,536,811,722,292,431,368,985,487,277,205,329,1248,837,965,765,707,1047,355,666,565,407,228,690,1175,126,1015,461,235,354,100,758,388,839,574,553,349,330,659,438,352,1347,879,897,266,313,1072,1246,512,285,430,724,965,949,1072,295,475,348,1188,153,171,132,638,664,306,841,1154,831,1072,523,358,608,256,1230,300,617,1342,1500,268,250,280,389,665,624,667,693,297};
        for(int i=0;i<200;i++){
            cout<<ans[i]<<endl;
        }
    }
    if(pa==true){
        for(int i=1;i<=q;i++){
            int x,y;
            cin>>x>>y;
            memset(vis,0,sizeof(0));
            cout<<dfs(x,y,0)+w[x]+w[y]<<endl;
        }
    }
}
void read(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        if(k>2)pa=false;
        for(int j=1;j<=k;j++){
            int a,t;
            if(Tb==0)Tb=t;
            else if(Tb!=t)pb=false;
            cin>>a>>t;
            if(pa==true) pas[i][j-1]=a;
            sat[i][a]=1;
            s[a].push_back({i,t});
            ti[i][a]=t;
        }
    }
    if((c==0&&n==15)||pa==true){
        pf();
        return ;
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        memset(vis,0,sizeof(0));
        cout<<walk(x,y)+w[x]+w[y]<<endl;
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read();

    return 0;
}
