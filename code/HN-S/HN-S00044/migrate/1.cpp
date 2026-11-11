#include<bits/stdc++.h>
using namespace std;
//由于只打算过第一二个点 所以哪怕只有一组数据也完全可以用字母代替路径。
int c=0,t=0,n=0,d=0;
long long p[30];
struct node{
    int to,nxt;
}edge[1000];
int cnt=0,head[20];
void add(int u,int v){
    edge[++cnt].to=v;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
}
//map<string,int> vis;
//map<string,int> vis;
vector<string> vis;
bool find(string s){
    for(auto& it:vis){
        if(it==s)return true;
    }
    return false;
}
int ans[20][20];//直接存点到点的路径总数
//直接搜索 恰好边权1
void bfs(int root,string vStr){
    //从谁出发 以A～Z代表的路径 可以把数据抽象成1～n了
    //宽艘？
    //cout<<"In bfs: root="<<root<<"  vStr="<<vStr<<"\n";
    for(int i=head[root];i;i=edge[i].nxt){
        int v=edge[i].to;
        vStr+=(char)(v+'A'-1);
        if(vStr.size()>n||find(vStr))break;
        //vis[vStr]=vStr.size();
        vis.push_back(vStr);
        ans[root][v]++;
        bfs(v,vStr);
    }
    return;
}
char n_to_c(int n){
    return (char)(n+1-'A');
}
void print_map(int root){
    for(int i=head[root];i;i=edge[i].nxt)
    {
        print_map(edge[i].to);
        cout<<head[i]<<"->"<<edge[i].to<<"\n";
    }
}
bool counter(char _begin,char _end){
    int ak[2],kkcnt=0;
    for(int i=0;i<vis.size();i++){
        string sstr=vis[i];
        if(sstr[0]==_begin&&sstr[sstr.size()-1]==_end)ak[++kkcnt]==sstr.size();
    }
    return ak[1]==ak[2];
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    cin>>c>>t;
    for(int ppp=1;ppp<=t;ppp++){
        cin>>n>>d;
        memset(head,0,sizeof(head));
        memset(ans,0,sizeof(ans));
        memset(p,0,sizeof(0));
        vis.clear();
        cnt=0;
        for(int i=1;i<=n;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(p[i]-p[j])<=d){
                    add(i,j);
                }
            }
        }
        print_map(1);
        for(int i=1;i<=n;i++){
            string k="";
            k+=(char)('A'+i-1);
            bfs(i,k);
        }
        int ans1=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j&&ans[i][j]==2&&counter(n_to_c(i),n_to_c(j))){
                    ans1++;
                }
            }
        }
        cout<<ans1<<"\n";
    }
    return 0;
}