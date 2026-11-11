#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[300010],cnt[300010];
void play(long long time){
    long long vis[300010]={0},pos[300010]={},visa[300010]={};
    deque<long long>d;
    for(long long i=time;i<=n;i++){
        if(vis[a[i]]==1){
            for(long long j=d.size();j>=pos[a[i]];j--){
                vis[visa[pos[a[i]]]]=0;
                d.pop_back();
            }
        }
        vis[a[i]]=1;
        pos[a[i]]=d.size()+1;
        visa[pos[a[i]]]=i;
        d.push_back(a[i]);
    }
    bool visdel[300010]={0};
    while(!d.empty()){
        long long now=d.front();
        d.pop_front();
        if(visdel[now]==0){
            cnt[now]++;
            visdel[now]=1;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        play(i);
    }
    for(long long i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
