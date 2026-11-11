#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<vector<pair<int,int>>> lin;
vector<int> dis;
int di(int a,int b){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pd;
    vector<int> dis(n+1,LLONG_MAX);
    dis[a]=0;
    pd.push({0,a});
    while(!pd.empty()){
        int a=pd.top().second;
        int b=pd.top().first;
        if(b!=dis[a]){
            continue;
        }
        for(auto dot:lin[a]){
            int x=dot.first;
            int y=dot.second;
            if(dis[x]>dis[a]+y){
                dis[x]=dis[a]+y;
                pd.push({dis[x],x});
            }
        }
    }
    return dis[b];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    vector<int> kou(m+1,0);

    lin.resize(m);
    dis.resize(n+1,LLONG_MAX);
    for(int i=1;i<=m;i++){
        cin>>kou[i];
    }
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        for(int j=0;j<num;j++){
            int tmp;
            cin>>tmp;
        }
    }
    for(int i=0;i<q;i++){
        int qi,zhong;
        cin>>qi>>zhong;
        if(qi==zhong){
            cout<<0<<endl;
        }else{
            int ans =di(qi,zhong);
            cout<<ans<<endl;
        }
        
    }
    
    return 0;
    
}
