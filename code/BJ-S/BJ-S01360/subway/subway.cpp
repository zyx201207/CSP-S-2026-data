#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define ll long long
using namespace std;

//ll lwt(int n,int m,int d,vector<int> &w,vector<vector<int> > &a,vector<vector<int> > &t,int x,int y){
//    ll res = 0;
//    res += w[x];
//    res += w[y];
//
//}

ll lwt(int n,int m,int d,vector<int> &w,vector<vector<int> > &a,vector<vector<int> > &t,int x,int y){
    ll res = 0;
    res += w[x];
    res += w[y];
    queue<pair<int,int> > q;
    pair<int,int> tmp = {x,0};
    q.push(tmp);
    int mps = 8;
    vector<bool> vs(w.size(),false);
    vs[x] = true;
    while(!q.empty()){
        pair<int,int> cc = q.front();
        q.pop();
        if(cc.first == y){
           mps = min(mps,cc.second);
        }
        for(int i = 0;i < a.size();i++){
            if(!vs[w[i]]){
                pair<int,int> tt = {w[i],cc.second + 1};
                q.push(tt);
                vs[w[i]] = true;
            }
        }
    }
    return res + mps * 2LL * t[0][0];
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;//input No.,No. of subways,No. of stations,the most a station can have
    //plan number
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    vector<int> w(m);
    for(int i = 0;i < m;i++){
        scanf("%d",&w[i]);
    }
    vector<vector<int> > a(n),t(n);
    for(int i = 0;i < n;i++){
        int k;
        scanf("%d",&k);
        a[i].resize(k);
        t[i].resize(k);
        for(int j = 0;j < k;j++){
            scanf("%d %d",&a[i][j],&t[i][j]);
        }
    }
    if(c >= 12 && c <= 19){
        for(int i = 0;i < q;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            printf("%lld\n",lwt(n,m,d,w,a,t,x,y));
        }
        return 0;
    }
    for(int i = 0;i < q;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%lld\n",lwt(n,m,d,w,a,t,x,y));
    }
    return 0;
}
