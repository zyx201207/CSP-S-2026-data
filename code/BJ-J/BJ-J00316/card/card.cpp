#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int ans[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        vector<int>v(m+1,0);
        deque<int>q;
        for(int j=i;j<=n;j++){
            if(v[a[j]]){
                while(!q.empty()&&q.front()!=a[j]){
                    v[q.front()]=0;
                    q.pop_front();
                }
                if(!q.empty())q.pop_front();
                q.push_back(a[j]);
            }else{
                v[a[j]]=1;
                q.push_front(a[j]);
            }
        }
        for(int j=1;j<=m;j++){
            if(v[j]){
                ans[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}