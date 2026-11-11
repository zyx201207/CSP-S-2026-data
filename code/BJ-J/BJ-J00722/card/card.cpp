#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,x;
    cin>>n>>m;
    int a[500005]={0},cnt[300005]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int game=1;game<=n;game++){
        bool in[300005]={0};
        stack<int> s;
        for(int i=game;i<=n;i++){
            x=a[i];
            if(in[x]==0){
                s.push(x);
                in[x]=1;
            }
            else{
                while(s.top()!=x){
                    in[s.top()]=0;
                    s.pop();
                }
            }
        }
        while(!s.empty()){
            cnt[s.top()]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
