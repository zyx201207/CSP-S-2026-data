
#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool vis[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    queue<int>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            q.push(a[j]);
            while(!q.empty()&&vis[a[j]==1){
                q.pop();
            }
            vis[a[j]]=1;
        }
    }
    for(int i=0;i<q.size();i++){
        cout<<q.front();
        q.pop();
    }
return 0;
}
