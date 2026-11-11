#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;
bool in_st[300005];
int cnt[300005];int a[500005];
stack<int>s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>0;i--){
        if(!in_st[a[i]]){
            s.push(a[i]);
            in_st[a[i]]=1;
        }else{
            while(s.top()!=a[i]){
                int k=s.top();
                in_st[k]=0;
                s.pop();
            }
        }
        for(int i=1;i<=m;i++){
            cnt[i]+=in_st[i];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
