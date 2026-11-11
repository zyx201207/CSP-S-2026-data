#include<bits/stdc++.h>
using namespace std;
long long m,n,a[1000000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int t[m+1],g[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            g[a[j]]++;
        }
        for(int =1;i<=n;i++){
            if(g[i]==2){

            }
        }

    }
}
