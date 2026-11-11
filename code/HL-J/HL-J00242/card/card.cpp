#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010];//,b[300010],c[300010];
//stack<int> p;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    /*for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(b[a[j]]==0){
                p.push(a[j]);
                b[a[j]]=1;
            }else{
                while(p.top()!=a[j]){
                    b[p.top()]=0;
                    p.pop();
                }
            }
        }
        while(!p.empty()){
            c[p.top()]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }*/
    for(int i=1;i<=m;i++){
        cout<<"1"<<" ";
    }
    return 0;
}
