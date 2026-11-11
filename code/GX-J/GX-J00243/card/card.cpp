#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],vis[500005],dis[500005];
deque<int>s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            while(dis[a[j]]!=0){
                dis[s.back()]=0;
                s.pop_back();
            }
            dis[a[j]]=1;
            s.push_back(a[j]);
        }
        for(int l=1;l<=s.size();l++){
            vis[s.front()]++;
            s.push_back(s.front());
            s.pop_front();
        }
    }
    for(int i=1;i<=m;i++) cout<<vis[i]<<' ';
    return 0;
}
