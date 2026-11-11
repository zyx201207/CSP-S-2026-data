#include<bits/stdc++.h>
using namespace std;
int n,m,ans[500010],a[500010],x[500010],num1,a1[500010],amt[500010];
stack<int>s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
            cin>>a[i];
            if(a[i]==a[i-1]) amt[num1]++;
            else {
                a1[++num1]=a[i];
                amt[num1]=1;
            }
    }
    for(int i=1;i<=num1;i++){
        while(!s.empty()) s.pop();
        for(int j=1;j<=m;j++) x[j]=0;
        for(int j=i;j<=num1;j++) {
            if(x[a1[j]]==0) {
                s.push(a1[j]);
                x[a1[j]]=1;
            }
            else{
                while(s.top()!=a1[j]){
                    x[s.top()]=0;
                    s.pop();
                }
            }
        }
        for(int j=1;j<=m;j++) if(x[j]) ans[j]+=amt[i];
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;

}
