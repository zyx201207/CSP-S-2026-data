#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m,k[10005],b=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>k[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(k[i]&k[j]>b){
                b=k[i]&k[j];
            }
        }
    }
    cout<<b
return 0;
}
