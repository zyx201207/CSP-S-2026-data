#include"bits/stdc++.h"

const int N=510,M=5e5+10,D=25;
const long long LL_MAX=1e18+10;

struct line{
    int st[M];
    int st_cnt;

    inline void add_st(int st_id){
        st[st_cnt+1]=st_id;
        ++st_cnt;
    }
};
struct station{
    int l[D];
    std::map<int,long long> t;
    int l_cnt;

    inline void add_l(int l_id,long long l_t){
        l[l_cnt+1]=l_id;
        t[l_id]=l_t;
        ++l_cnt;
    }
};

int c,n,m,d,q;
long long w[M];
//line l[N];
station st[M];
long long conn_l_c[N][N];
int conn_l[N][N];
int conn_l_cnt[N];
std::unordered_set<int> is_l_conn[N];
long long l_dis[N];

inline void add_conn_l(int l1_id,int l2_id){
    if(is_l_conn[l1_id].count(l2_id)!=0){
        return;
    }
    conn_l[l1_id][conn_l_cnt[l1_id]+1]=l2_id;
    ++conn_l_cnt[l1_id];
    is_l_conn[l1_id].insert(l2_id);
}
inline void reset_l_dis(){
    for(int i=1;i<=n;i++){
        l_dis[i]=LL_MAX;
    }
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    std::cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        std::cin>>w[i];
    }
    {
    int k=0,a=0;
    long long t=0;
    for(int i=1;i<=n;i++){
        std::cin>>k;
        for(int j=1;j<=k;j++){
            std::cin>>a>>t;
            //l[i].add_st(a);
            st[a].add_l(i,t);
        }
    }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            conn_l_c[i][j]=LL_MAX;
        }
        conn_l_cnt[i]=0;
    }
    {
    long long cost=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=st[i].l_cnt;j++){
            for(int k=1;k<=st[i].l_cnt;k++){
                int l1=st[i].l[j],l2=st[i].l[k];
                //std::cout<<"[Debug]:"<<i<<","<<st[i].l_cnt<<","<<l1<<","<<l2<<std::endl;
                add_conn_l(l1,l2);
                if(l1==l2){
                    conn_l_c[l1][l2]=0;
                }
                else{
                    cost=st[i].t[l1]+st[i].t[l2];
                    //std::cout<<"[Debug]:"<<l1<<","<<l2<<"|"<<cost<<std::endl;
                    conn_l_c[l1][l2]=std::min(conn_l_c[l1][l2],cost);
                }
            }
        }
    }
    }
/*
    for(int i=1;i<=n;i++){
        std::cout<<"[Debug]:"<<i<<"|";
        for(int j=1;j<=conn_l_cnt[i];j++){
            std::cout<<conn_l[i][j];
            if(j!=conn_l_cnt[i]){
                std::cout<<",";
            }
        }
        std::cout<<std::endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            std::cout<<"[Debug]:"<<i<<","<<j<<"|"
            <<conn_l_c[i][j]<<std::endl;
        }
    }
*/
    int x=0,y=0;
    std::queue<int> t;
    long long ans=LL_MAX;
    for(int i=1;i<=q;i++){
        std::cin>>x>>y;
        int stt_l=0;
        ans=LL_MAX;
        for(int j=1;j<=st[x].l_cnt;j++){
            reset_l_dis();
            t=std::queue<int>();
            stt_l=st[x].l[j];
            t.push(stt_l);
            l_dis[stt_l]=0;
            while(!t.empty()){
                int cur_l=t.front();
                t.pop();
                for(int k=1;k<=conn_l_cnt[cur_l];k++){
                    int tar_l=conn_l[cur_l][k];
                    int dis=l_dis[cur_l]+conn_l_c[cur_l][tar_l];
                    if(dis<l_dis[tar_l]){
                        l_dis[tar_l]=dis;
                        t.push(tar_l);
                    }
                }
            }
/*
            std::cout<<"[Debug]:";
            for(int i=1;i<=n;i++){
                std::cout<<l_dis[i];
                if(i!=n){
                    std::cout<<",";
                }
            }
            std::cout<<std::endl;
*/
            int end_l=0;
            for(int k=1;k<=st[y].l_cnt;k++){
                end_l=st[y].l[k];
                //std::cout<<"[Debug]:"<<stt_l<<","<<end_l<<std::endl;
                ans=std::min(ans,l_dis[end_l]+st[x].t[stt_l]+st[y].t[end_l]);
                //std::cout<<"[Debug]:"<<stt_l<<","<<end_l<<std::endl;
            }
        }
        ans=ans+w[x]+w[y];
        std::cout<<ans<<std::endl;
    }
    return 0;
}
