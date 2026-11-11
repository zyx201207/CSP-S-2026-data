#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],f[300005],t[300005]={};
void check(int ii){
    memset(f,-1,sizeof(f));
    stack<int>m;
    for(int i=ii;i<=n;i++){
            if(f[a[i]]==-1){
                f[a[i]]=m.size()+1;
            }else{
                while(m.size()>=f[a[i]]){
                    if(m.top()!=a[i])f[m.top()]=-1;
                    m.pop();
                }
            }
        m.push(a[i]);
    }
    while(!m.empty()){
      t[m.top()]++;
       m.pop();
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
for(int i=1;i<=n;i++){
    check(i);
}
for(int i=1;i<=m;i++){
    cout<<t[i]<<" ";
}
return 0;
}
