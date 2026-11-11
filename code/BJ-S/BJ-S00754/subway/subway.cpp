#include <bits/stdc++.h>
using namespace std;
long long a=0,b=0,c=0,d=0,e=0;
long long aa[20005]={};
long long ab[20005][21]={};
long long road1[20005][500]={};
long long road2[2005][20005]={};
vector<vector<pair<long long,long long>>>road3;
long long dij(long long x,long long y){
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,less<pair<long long,long long>>>dj;
    long long cnt[20005]={};
    for(long long i=0;i!=road3[x].size();i++){
        if(road3[x][i].second==0)continue;
        dj.push(road3[x][i]);
    }
    while(dj.top().second!=y){
        for(long long i=0;i!=road3[dj.top().second].size();i++){
            if(dj.top().first==0)break;
            if(road3[dj.top().second][i].first==0)continue;
            pair<long long ,long long>k;
            k.first=road3[dj.top().second][i].first+dj.top().first;
            k.second=road3[dj.top().second][i].second;
            dj.push(k);
        }
        dj.pop();
    }
    return dj.top().first;
}

int main(){
    road3.resize(20005);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>a>>b>>c>>d>>e;
    for(long long i=1;i!=c+1;i++){
        cin>>aa[i];
    }
    for(long long i=0;i!=b;i++){
        long long n=0;
        cin>>n;
        for(long long j=0;j!=n;j++){
            long long m=0;
            cin>>m;
            cin>>road1[m][i];
            ab[m][0]++;
            ab[m][ab[m][0]]=i;
        }
    }
    long long qu[500005][2]={};
    for(long long i=0;i!=e;i++){
        cin>>qu[i][0]>>qu[i][1];
    }
    for(long long i=1;i!=c+1;i++){
        for(long long j=1;j!=c+1;j++){
            road2[i][j]=1e15;
        }
        road2[i][i]=0;
    }
    for(long long i=1;i!=c+1;i++){
        for(long long j=1;j!=c+1;j++){
            for(long long n=1;n!=ab[i][0]+1;n++){
                if(road1[j][ab[i][n]]!=0){
                    road2[i][j]=min(road2[i][j],road1[j][ab[i][n]]+road1[i][ab[i][n]]);
                    road2[j][i]=min(road2[j][i],road1[j][ab[i][n]]+road1[i][ab[i][n]]);
                }
            }
        }
    }
    for(long long i=1;i!=c+1;i++){
        for(long long j=1;j!=c+1;j++){
            if(road2[i][j]>0&&road2[i][j]<1e14){
                pair<long long ,long long >k;
                k.first=road2[i][j];k.second=j;
                road3[i].push_back(k);
            }
            //if(road2[i][j]<1000000)cout<<road2[i][j];
            //cout<<'*';
        }
        //cout<<endl;
    }
    for(long long i=0;i!=e;i++){
        cout<<aa[qu[i][0]]+aa[qu[i][1]]+dij(qu[i][0],qu[i][1])<<endl;
    }
    return 0;
}
