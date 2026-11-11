#include<bits/stdc++.h>
using namespace std;
int n,m;
deque<int> q;
int a[500005];
int k;
int l;
int vis[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            vis[i]++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<vis[i]<<" ";
    }
    return 0;
}