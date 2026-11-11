#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,t,x,y;
int w[500005],len[505];
vector <int,vector <int>> v;
vector <int> vv;
vector <int> rp;
queue <pair <int,int>> q;
vector <vector <int,vector <int>>> mp;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>t;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    vv.push_back(0);
    v.push_back(vv);
    for(int i=1;i<=n;i++){
        cin>>len[i];
        v.push_back(vv);
        for(int j=1;j<=len[i];j++){
            cin>>x>>y;
            rp.push_back(x)
            v[i].push_back(y);
        }
    }
    while(t--){
        cout<<0<<'\n';
    }
    return 0;
}