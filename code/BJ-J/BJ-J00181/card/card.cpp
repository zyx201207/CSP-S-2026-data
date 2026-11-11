#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m;
int a[N], cnt[M];
bool vis[M] = {0};
stack<int> st;
void Pop(int k){
    while(st.top() != k){
        vis[st.top()] = false;
        st.pop();
    }
}
void num(){
    while(!st.empty()){
        vis[st.top()] = false;
        cnt[st.top()]++;
        st.pop();
    }
}
void add(int k){
    if(!vis[k]){
        st.push(k);
        vis[k] = true;
    }else{
        Pop(k);
    }
}
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            add(a[j]);
        }
        num();
    }
    for(int i = 1; i <= m; i++) cout<<cnt[i]<<" ";
    cout<<"\n";
    return 0;
}