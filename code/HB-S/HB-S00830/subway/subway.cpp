#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
long long c,n,m,d,q,k;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过,以及出行计划数,第 i 条线路经过的地铁站数
long long w[MAXN],a[MAXN],t[MAXN],ans[MAXN];//w:从每个地铁站的地铁口走到站厅需要的时间
                                            //a i,j 表示第 i 条线路经过的第 j 个地铁站
                                            //t i,j 表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){cin>>w[i];}
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>a[i]>>t[i];
    }

    return 0;
}
