#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],tt[500010][600],maxx=1,cnt=0,te=1,T;
vector<int> ra[500010];
queue<int> zh,bs;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int x,su[500010];
        vector<int> ve;
        scanf("%d",&x);
        for(int j=1;j<=x;j++){
            int y;
            scanf("%d",&y);
            scanf("%d",&tt[y][i]);
            ve.push_back(y);
            T=tt[y][i];
        }
        for(int j=0;j<ve.size();j++){
            for(int k=0;k<ve.size();k++){
                ra[ve[j]].push_back(ve[k]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        while(zh.empty()==0) zh.pop();
        while(bs.empty()==0) bs.pop();
        int fr,to,sum=0;
        scanf("%d%d",&fr,&to);
        zh.push(fr);
        bs.push(w[fr]+w[to]);
        while(zh.empty()==0){
            int zt=zh.front(),ss=bs.front();
            if(zt==to){
                cout<<ss+T<<endl;
                break;
            }
            for(int i=0;i<ra[zt].size();i++){
                zh.push(ra[zt][i]);
                bs.push(ss+T);
            }
            zh.pop();
            bs.pop();
        }
    }
    return 0;
}
