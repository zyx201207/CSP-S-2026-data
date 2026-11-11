#include<bits/stdc++.h>
using namespace std;
struct hhh{
    int a,va;
};
bool cmp(hhh a,hhh b){
    return a.va<b.va;
};
int c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;//c, n, m, d, q,分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过,以及出行计划数
    vector<int>w(n+1,0);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    if(c<=11&&c>=7){
        int sub[220][220];
        vector<int>b[220];
        for(int i=1;i<=n;i++){
            int k,h=0,l[3];
            cin>>k;
            for(int i=1;i<=k;i++){
                int y;
                scanf("%d%d",&l[i],&y);
                h+=y;
            }
            if(k>1){
                sub[l[1]][l[2]]=h;
                sub[l[2]][l[1]]=h;
                b[l[1]].push_back(l[2]);
                b[l[2]].push_back(l[1]);
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            int ans=w[x]+w[y];
            vector<hhh>vc;
            hhh e;
            e.a=x;
            e.va=0;
            vc.push_back(e);
            int fl=1;
            while(fl){
                sort(vc.begin(),vc.end(),cmp);
                for(auto auv:b[vc[0].a]){
                    int llll=vc[0].va+sub[auv][vc[0].a];
                    if(auv==y){
                        ans+=llll;
                        fl=0;
                        break;
                    }
                    hhh bbb;
                    bbb.a=auv;
                    bbb.va=llll;
                    vc.push_back(bbb);
                }
            }
            cout<<ans<<"\n";
        }
    }
}
