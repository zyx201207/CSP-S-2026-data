#include<bits/stdc++.h>
using namespace std;
int n,m,a[200100],t[200100];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            bool flag=0;
            for(int k=j+1;k<=n;k++){
                if(a[k]==a[j]){
                    j=k-1;
                    flag=1;
                    break;
                }
            }if(!flag){
                t[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t[i]<<' ';
    }
    return 0;
}
