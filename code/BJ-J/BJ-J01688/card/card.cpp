#include<bits/stdc++.h>
using namespace std;
int n,m,g[500110],j[500110]={0};
stack<int> k;
bool v[5001100]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>g[i];
    }
    int s=1;
    while(s<=n){
        for(int i=s;i<=n;i++){
           
            if(v[g[i]]==1){
                while(k.top()!=g[i]){
                    v[k.top()]=0;
                    k.pop();
                }
            }
            else{
                 k.push(g[i]);
                 v[g[i]]=1;
            } 
        }
        while(!k.empty()){
            j[k.top()]++;
            v[k.top()]=0;
                    k.pop();
                }
                s++;
    }

    for(int i=1;i<=m;i++){
        cout<<j[i]<<" ";
    }
    return 0;
}
