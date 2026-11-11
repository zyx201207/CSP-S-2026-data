#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>G1[514114];
vector<pair<int,int>>G2[514114];
map<int,vector<long long>>dist;
int n,m,d,q;
long long dij(int s,int t){
    vector<long long>dis(m+1,LLONG_MAX);
    //{w,v};
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    q.push({0LL,s});
    while(!q.empty()){
        pair<long long,int>tp=q.top();
        q.pop();
        if(dis[tp.second]<tp.first)continue;
        dis[tp.second]=tp.first;
        //cout<<"dis["<<tp.second<<"] == "<<dis[tp.second]<<"\n";
        for(pair<int,int> i:G2[tp.second]){
            for(pair<int,int> j:G1[i.first]){
                if(j.first==tp.second)continue;
                q.push({i.second+j.second+tp.first,j.first});
                //cout<<"push "<<tp.second<<" "<<j.first<<" "<<i.second+j.second+tp.first<<"\n";
                //cout<<"now size:"<<q.size()<<"\n";
            }
        }
    }
    dist[s]=dis;
    return dis[t];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int tmptmptmp114514666;//orz
    cin>>tmptmptmp114514666>>n>>m>>d>>q;
    vector<int>st_(m+1);
    for(int i=1;i<=m;i++){
        cin>>st_[i];
    }
    int ktmp,atmp,ttmp;
    for(int i=1;i<=n;i++){
        cin>>ktmp;
        for(int j=0;j<ktmp;j++){
            cin>>atmp>>ttmp;
            G1[i].push_back({atmp,ttmp});
            G2[atmp].push_back({i,ttmp});
        }
    }
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        if(!dist[x].empty()){
			cout<<dist[x][y]+st_[x]+st_[y]<<endl;
		}
		else{
			cout<<dij(x,y)+st_[x]+st_[y]<<endl;
		}
    }
    return 0;
}
