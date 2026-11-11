#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll Station=50000,LINE=501;

ll m,n,d,q,Exit_To_Lobby[Station],Lobby_to_Train[LINE][Station],LineMap[LINE][Station],Start,End,StationMap[Station][LINE];
ll ans=1000000000;
bool blacklist[LINE];
bool flag=false;

void dfs(ll pos,ll line,ll time){
    //cout << pos << line << time;
    if(LineMap[line][End]==1){
        ans=min(ans,time+Lobby_to_Train[line][End]);
     //   cout << 666;
        return;
      //  cout << 666;
    }
    for(int i=1;i<=m;i++){
        if(StationMap[i][line]==1){
            for(int j=1;j<=n;j++){
                if(LineMap[j][i]==1&&j!=line&&blacklist[j]!=true){
                    blacklist[line]=true;
                //    cout <<i<<' '<<Lobby_to_Train[line][i]<<' '<<Lobby_to_Train[j][i];
                    dfs(i,j,time+Lobby_to_Train[line][i]+Lobby_to_Train[j][i]);
                    blacklist[line]=false;
                }
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll num;
    cin >> num >>n >> m>> d>>q;
    for(ll i=1;i<=m;i++){
        ll x;
        cin >> x;
        Exit_To_Lobby[i]=x;
    }//The time of exit to lobby for each Line
    for(ll i=1;i<=n;i++){
        ll stanum;
        cin >> stanum;
        for(ll j=1;j<=stanum;j++){
            ll st,ti;
            cin >> st>>ti;
            LineMap[i][st]=1;
            StationMap[st][i]=1;
            Lobby_to_Train[i][st]=ti;
        }
    }//Complete the info of Lines

    for(ll i=1;i<=q;i++){
     //   cout <<LineMap[i][End]<<endl;
        cin >> Start >> End;
        for(ll i=1;i<=n;i++){
            if(LineMap[i][Start]==1){
                    if(LineMap[i][End]==1){
                        flag=true;
                        cout<<Exit_To_Lobby[Start]+Lobby_to_Train[i][Start]+Lobby_to_Train[i][End]+Exit_To_Lobby[End]<<endl;
                        break;
                    }else{

                        dfs(Start,i,Exit_To_Lobby[Start]+Lobby_to_Train[i][Start]+Exit_To_Lobby[End]);
                    }
            }
        }

        if(flag==false) cout << ans<<endl;
       // cout <<'-'<<flag;
        flag=false;
        ans=1000000000;
       // cout<<'-'<<endl;
    }//R's travel plan && management && out
    return 0;
}


/*
 0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
                        */



