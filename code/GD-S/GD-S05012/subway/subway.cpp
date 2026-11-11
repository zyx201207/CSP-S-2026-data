#include<bits/stdc++.h>
using namespace std;
int w[500001],cost[500001];
bool v[500001],v1[500001];
int sizes[500001],k[501];
struct dot{
    vector<int> so;
    vector<int> co;
};
struct line{
    vector<int> so;
};
dot d[500001];line D[501];
bool fuc(int A,int B){
    return cost[A]<cost[B];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout)
    int c,n,m,d1,q;
    cin>>c>>n>>m>>d1>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int tmp1,tmp2;
            cin>>tmp1>>tmp2;
            d[tmp1].so.push_back(i);
            d[tmp1].co.push_back(tmp2);
            sizes[tmp1]++;
            D[i].so.push_back(tmp1);
        }
    }
    for(int r=1;r<=q;r++){
        int x1,y1;
        vector<int> djs;
        memset(v,0,sizeof(v));
        memset(v1,0,sizeof(v1));
        memset(cost,-1,sizeof(cost));
        cin>>x1>>y1;
        djs.push_back(x1);
        while(cost[y1]==-1){
            sort(djs.begin(),djs.end(),fuc);
            v[djs[0]]=true;
            for(int i=0;i<sizes[djs[0]];i++){
                for(int j=0;j<k[d[djs[0]].so[i]];j++){
                    if(!v[D[d[djs[0]].so[i]].so[j]]){
                        if(!v1[D[d[djs[0]].so[i]].so[j]]){
                            djs.push_back(D[d[djs[0]].so[i]].so[j]);
                            v1[D[d[djs[0]].so[i]].so[j]]=true;
                        }
                        cost[j]=min(cost[j],cost[djs[0]]+d[djs[0]].co[i]+d[D[d[djs[0]].so[i]].so[j]].co[d[djs[0]].so[i]]);
                    }
                }
            }
            djs.erase(djs.begin());
        }
        cout<<cost[y1]+w[x1]+w[y1];
    }
    return 0;
}
