#include<iostream>
#include<stack>
#include<vector>
#include<cstdio>
using namespace std;
stack<int> q;
int f[300005];
int n,m,a[300005];
void find(int x){
    vector<int> g;
    while(!q.empty()){
        if(q.top()==x){
            q.pop();
            return ;
        }
        g.push_back(q.top());
        q.pop();
    }
    for(int i=g.size()-1;i>=0;i--){
        q.push(g[i]);
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            find(a[j]);
            q.push(a[j]);
        }
        while(!q.empty()){
            f[q.top()]++;
            q.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<f[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
