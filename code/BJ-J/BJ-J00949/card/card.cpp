#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500100];
int cnt[300100];
void work(int start){
    stack<int> q;
    map<int,int> mp;
    for(int i=start;i<=n;i++){
        if(mp[a[i]]==0){
            mp[a[i]]=1;
            q.push(a[i]);
        }else{
            while(!q.empty()&&q.top()!=a[i]){
                mp[q.top()]=0;
                q.pop();
            }
            if(!q.empty())q.pop();
            q.push(a[i]);
            mp[a[i]]=1;
        }
    }
    while(!q.empty()){
        cnt[q.top()]++;
        q.pop();
    }
}
int id[300100];
void workf(){
    for(int i=1;i<=n;i++){
        id[a[i]]=i;
    }
    for(int i=1;i<=m;i++){
        cnt[i]=id[i];
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
}
bool flag=true;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        if(a[i]>a[i+1])flag=false;
    }
    if(flag){
        workf();
        return 0;
    }
    for(int i=1;i<=n;i++){
        work(i);
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}