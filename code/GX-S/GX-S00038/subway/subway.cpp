#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct sub{
    int a,t;
}subway[501][21];
int w[500001],d1[501];
int bfs(int s,int e,vector<int>visz,vector<int>visx,int time,int lastx,int lastz){
    if(s==e){
        return time;
    }
    int ansans=INT_MAX;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=d1[i];j++){
            if(subway[i][j].a==s){
                for(int k=1;k<=d1[i];k++){
                    int is=0,t=0;
                    for(int l=0;l<visz.size();l++){
                        if(subway[i][k].a==visz[l]){
                            is=1;
                        }
                    }
                    if(!is){
                        if(lastx==i){
                        visx.push_back(i);
                        visz.push_back(subway[i][k].a);
                        ansans=min(ansans,bfs(subway[i][k].a,e,visz,visx,time+subway[i][k].t,i,k));
                        visx.pop_back();
                        visz.pop_back();
                        }
                        else
                        {
                        visx.push_back(lastx);
                        visx.push_back(i);
                        visz.push_back(subway[lastx][lastz].a);
                        visz.push_back(subway[i][k].a);
                        ansans=min(ansans,bfs(subway[i][k].a,e,visz,visx,time+subway[i][k].t+subway[lastx][lastz].t,i,k));
                        visx.pop_back();
                        visx.pop_back();
                        visz.pop_back();
                        visz.pop_back();
                        }
                    }
                }
            }
        }
    return ansans;
}
bool cmp(sub l,sub r){
    return l.a<r.a;
}
vector<int>visz,visx;
void sample(){
    int v1,v2;
    cin>>v1>>v2;
    int ans=INT_MAX;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=d1[i];j++){
            if(subway[i][j].a==v1){
        visz.push_back(v1);
        visx.push_back(i);
        ans=min(ans,bfs(v1,v2,visz,visx,w[v1]+w[v2],i,j));
        visx.pop_back();
        visz.pop_back();}
    }
    cout<<ans<<endl;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>d1[i];
        for(int j=1;j<=d1[i];j++)
            cin>>subway[i][j].a>>subway[i][j].t;
        sort(subway[i]+1,subway[i]+d1[i]+1,cmp);
    }
    for(int i=1;i<=q;i++)
         sample();
    return 0;
}
