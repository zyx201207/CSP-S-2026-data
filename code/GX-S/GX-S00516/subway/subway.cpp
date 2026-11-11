#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[5050],k[5050],a[5050][5050],t[5050][5050],can_arrive[5050][5050];
long long min_Walk_Time,ans[500500];
bool subwayLine_Have_Used[5050],station_Have_arrived[5050];
pair<int,int> r[500500];
void func(int now_Station,int goal,long long walk_Time){
    if(goal==now_Station){
        min_Walk_Time=min(min_Walk_Time,walk_Time);
        return;
    }
    for(int i=1;i<=n;i++){
        if(subwayLine_Have_Used[i]==false && can_arrive[i][now_Station]!=0){
            for(int j=1;j<=k[i];j++){
                if(station_Have_arrived[a[i][j]]==false && a[i][j]!=now_Station && walk_Time+t[i][j]+t[i][can_arrive[i][now_Station]]<min_Walk_Time){
                    subwayLine_Have_Used[i]=true;
                    station_Have_arrived[a[i][j]]=true;
                    func(a[i][j],goal,walk_Time+t[i][j]+t[i][can_arrive[i][now_Station]]);
                    station_Have_arrived[a[i][j]]=false;
                }
            }
        }
        subwayLine_Have_Used[i]=false;
    }
}
int main(){
    freopen("subway1.in","r",stdin);
    freopen("subway1.ans","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            can_arrive[i][a[i][j]]=j;
        }
    }
    for(int i=1;i<=q;i++){
        min_Walk_Time=100000000000;
        cin>>r[i].first>>r[i].second;
        func(r[i].first,r[i].second,w[r[i].first]+w[r[i].second]);
        ans[i]=min_Walk_Time;
    }
    for(int i=1;i<=q;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
