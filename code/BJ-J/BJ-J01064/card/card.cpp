#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int zhuo[500005];
int ju[500005];
stack<int>pai;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int i=1;i<=n;i++){
        memset(zhuo,0,sizeof(zhuo));
        for(int j=i;j<=n;j++){
            zhuo[a[j]]++;
            if(zhuo[a[j]]>1){
                while(zhuo[a[j]]>1){
                    zhuo[pai.top()]--;
                    pai.pop();
                }
            }pai.push(a[j]);
        }
        while(pai.size()){
            ju[pai.top()]++;
            pai.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ju[i]<<' ';
    }
    return 0;
}
