#include <bits/stdc++.h>
using namespace std;
using ll = long long;


long long c,n,m,d,q;
//数c,n,m,d,q，分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
int luxian[505][500005];
int tluxian[505][500005];
int zz[505];
int w[505];

ll dfs1(int l,int r){
    if(l==r) return 0;
    else if(zz[l]) return -1;
    ll ans = LLONG_MAX;
    for(int i = 0;i<=n;i++){
        if(luxian[i][1]==l){
            ll ans1 = tluxian[i][1]+tluxian[i][2];
            zz[l] = 1;
            ll t = dfs1(luxian[i][2],r);
            if(t == 0){
                ans1+=tluxian[i][2];
                ans = min(ans1,ans);
            }else if(t!=-1){
                ans1+=t;
                ans = min(ans1,ans);
            }
            zz[l] = 0;
        }else if(luxian[i][2]==l){
            ll ans1 = tluxian[i][1]+tluxian[i][2];
            zz[l] = 1;
            ll t = dfs1(luxian[i][1],r);
            if(t == 0){
                ans1+=tluxian[i][1];
                ans = min(ans1,ans);
            }else if(t!=-1){
                ans1+=t;
                ans = min(ans1,ans);
            }
            zz[l] = 0;
        }
    }
    return (ans == LLONG_MAX? 0:ans);
}

/*int dfs1(int l,int r){
    if(l==r) return 0;
    for(int i = 0;i<=n;i++){
        if(luxian[i][l]!=0){
            for(int j = 0;j<=500005;j++){
                if(luxian[i][j]!=0){
                    dfs()
                }
            }
        }
    }

}*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 0;i<m;i++){
        cin >> w[i];
    }
    if(7<=c&&c<=11){
        for(int i = 1;i<=n;i++){
            cin >> luxian[i][0];
            for(int j = 1;j<=luxian[i][0];i++){
                cin >> luxian[i][j];
                cin >> tluxian[i][j];
            }
        }
        while(q--){
            memset(zz,0,sizeof(zz));
            int l,r;
            cin >> l >> r;
            cout << w[l]+dfs1(l,r)+w[r] << "\n";
        }
    }else{
        for(int i = 1;i<=n;i++){
            cin >> luxian[i][0];
            for(int j = 1;j<=luxian[i][0];i++){
                int z;
                cin >> z;
                luxian[i][z]++;
                cin >> tluxian[i][z];
            }
        }
    }


    while(q--){
        int l,r;
        cin >> l >> r;

    }
    //cout << ans;
}
