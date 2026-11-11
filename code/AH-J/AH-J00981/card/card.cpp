#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int n,m;
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    int a[n+1]={0};
    int x[m+1]={0};
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int T=1;T<=n;T++){
        int v[m+1]={0};
        for(int i=T;i<=n;i++){
            if(v[a[i]]==1){
                while(s.top()!=a[i]){
                    v[s.top()]=0;
                    s.pop();
                }
                s.pop();
            }
            s.push(a[i]);
            v[a[i]]=1;
        }
        for(int i=1;i<=m;i++){
            if(v[i]==1){
                x[i]++;
            }
        }
        while(!s.empty()){
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",x[i]);
    }

    return 0;
}
