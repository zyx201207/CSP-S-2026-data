#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005];
deque<int> q;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(auto &x:q){
                if(x==a[j]){
                    while(q.back()!=x) q.pop_back();
                    q.pop_back();
                    break;
                }
            }
            q.push_back(a[j]);
        }
        while(!q.empty()){
            ++cnt[q.front()];
            q.pop_front();
        }
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
    return 0;
}
