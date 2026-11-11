#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+5,M=3e5+5;
int a[N];
int ans[M];
queue<int> desk;
queue<int> q;
void eras(int x){
    queue<int> tmp;
    tmp=desk;
}
bool query(int x){
    while(q.size()){
        int q=desk.front();desk.pop();
        if(q==x) return 0;
    }
    return 1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card,out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        q.push(a);
    }
    for(int t=1;t<=n;t++){
        while(q.size()){
            int d=q.front();
            if(query(d)){
                q.pop();
                desk.push(d);
            }else{
                q.pop();
                for(int i=0;i<desk.size();i++){
                    if(desk[i]==d){
                        erase(d[i]);
                        erase(d[i]+1);
                    }
                }
                desk.push(d);
            }
            for(int i=0;i<desk.size();i++){
                ans[desk[i]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
