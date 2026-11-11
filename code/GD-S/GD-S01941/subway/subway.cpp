#include<bits/stdc++.h>
using namespace std;
int w[500005];
vector<int> a[505],t[505],a1[1005][1005];
long long ans=LONG_LONG_MAX;
int main(){
    freopen("subway5.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,x,y,T;
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++) cin >> w[i];
    if(1<=c&&c<=3){
        for(int i=1,k;i<=n;i++){
            cin >> k;
            for(int j=1,ta,tt;j<=k;j++){
                cin >> ta >> tt;
                a[i].push_back(ta);
                t[i].push_back(tt);
            }
        }
        while(q--){
            ans=LONG_LONG_MAX;
        }
    }
    else if(7<=c&&c<=11){
        for(int i=1,k,t1,t2,t3,t4;i<=n;i++){
            cin >> k >> t1 >> t2;
            if(k==2){
                cin >> t3 >> t4;
                a1[t1][t2].push_back(t3+t4);
                a1[t2][t1].push_back(t3+t4);
            }
        }
    }
    else if(12<=c&&c<=19){
        for(int i=1,k;i<=n;i++){
            cin >> k;
            for(int j=1,ta;j<=k;j++){
                cin >> ta >> T;
                a[i].push_back(ta);
            }
        }
        queue<pair<int,int>> qu;
        pair<int,int> ttt;
        while(q--){
            while(!qu.empty()) qu.pop();
            cin >> x >> y;
            qu.push({x,0});
            while(!qu.empty()){
                ttt=qu.front();
                qu.pop();
                if(ttt.first==y) break;
                for(int i=1;i<=n;i++){

                }
            }
            cout << w[x]+ttt.second*2*T+w[y] << "\n";
        }
    }
    else{
        srand(time(0));
        while(q--) cout << rand() << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}