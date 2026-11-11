#include<bits/stdc++.h>
using namespace std;
int a[500001];
int n,m;
vector<int>cnt;
bool f(stack<int>s,int k){
    while(!s.empty()){
        int x=s.top();
        s.pop();
        if(x==k)return true;
    }
    return false;
}
void game(int i){
    stack<int>table;
    for(int j=i;j<=n;j++){
        if(f(table,a[j])){
            while(f(table,a[j]))table.pop();
        }
        table.push(a[j]);
    }
    for(int k=1;k<=m;k++){
        if(f(table,k))cnt[k]++;
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        game(i);
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
