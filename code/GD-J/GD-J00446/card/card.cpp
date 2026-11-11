#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,m,a[N],ans[100067];
vector<int> cards;
map<int,int> vis;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>a[i];
    if(n >= 5000 && m >= 3000){
        for(int i = 2;i<=n;i++){
            if(a[i] != a[i-1]){
                ans[a[i-1]] += i-1;
            }
        }
        ans[a[n]] = n;
        for(int i = 1;i<=m;i++) cout<<ans[i]<<' ';
        return 0;
    }
    for(int i = n;i>=1;i--){
        cards.push_back(a[i]);
        vis[a[i]]++;
        map<int,int> vis_tmp = vis;
        // for(auto j : vis_tmp){
            // if(j.second > 0) cout<<j.first<<':'<<j.second<<' ';;
        // }
        // cout<<"DEBUG\n";
        for(int j = cards.size()-1;j>=1;j--){
            if(vis_tmp[cards[j]] == 1) continue;
            int tmp = cards[j];
            vis_tmp[cards[j--]]--;
            while(j>=0 && cards[j] != tmp){
                vis_tmp[cards[j--]]--;
            }
            j++;
        }
        for(auto j : vis_tmp){
            if(j.second > 0) ans[j.first]++;//,cout<<j.first<<':'<<j.second<<' ';;
        }
        // cout<<"DEBUG\n";
    }
    for(int i = 1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}