#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 100;
int n,m,a[N],ans,pos;
bool c[N][31];
vector<int>G[N];
vector<int> vec;
vector<int> vec2;
bool mark = false;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        for(int j = 0;(1 << j) <= a[i];j++){
            int x = a[i] >> j;
            if(x & 1 == 1){
                c[i][j] = true;
                G[j].push_back(i);
            }
        }
    }
    for(int i = 30;i>=0;i--){
        if(mark == false && (int)G[i].size() >= m){
            mark = true;
            pos = i;
            ans += (1 << i);
            for(auto v : G[i]) vec.push_back(v);
        }
        else if(mark == true){
            int cnt = 0;
            for(auto v : vec){
                if(c[v][i] == true) ++cnt;
            }
            if(cnt >= m){
                ans += (1 << i);
                vec2.clear();
                for(auto v : vec) vec2.push_back(v);
                vec.clear();
                for(auto v : vec2){
                    if(c[v][i] == true){
                        vec.push_back(v);
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}