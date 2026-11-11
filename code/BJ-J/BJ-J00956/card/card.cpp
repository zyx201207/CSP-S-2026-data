#include <bits/stdc++.h>
using namespace std;
int a[500009],mm[300009]={0},near[300009],uq[500009];
bool exi[500009];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    memset(near,-1,sizeof(near));
    memset(uq,-1,sizeof(uq));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(near[a[i]]!=-1) uq[i]=near[a[i]];
        near[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        memset(exi,0,sizeof(exi));
        stack<int> s;
        for(int cur=i;cur<=n;cur++){
            if(uq[cur]!=-1&&exi[a[cur]]){
                while(s.top()!=a[cur] && !s.empty()){
                    exi[s.top()]=0;
                    s.pop();
                }
            }else{
                exi[a[cur]]=1;
                s.push(a[cur]);
            }
        }
        while(!s.empty()){
            mm[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++) cout<<mm[i]<<' ';
    return 0;
}
