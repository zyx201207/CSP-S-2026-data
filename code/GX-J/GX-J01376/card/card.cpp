#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;cin>>n>>m;
    int a[n]={};
    for(int i=0;i<n;i++)
        cin>>a[i];

    int cnt[m+1]={};
    for(int i=1;i<=n;i++){
        int fron=0;
        int line[n]={};
        for(int j=i-1;j<=n;j++){
            line[fron]=a[j];
            fron++;
        }
        for(int j=1;j<=fron;j++){
            if(line[j]==i){
                cnt[i]++;
                continue;
            }
        }

    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }

    return 0;
}
