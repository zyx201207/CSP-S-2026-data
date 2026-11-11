#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],card[N],num[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[N];}
        for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(card[j]==a[i]){
                for(int k=j;k<i;k++){
                    card[k]=0;
                }
            }
        }
        card[i]=a[i];
        if(i==n){
            for(int j=1;j<=n;j++){
                num[j]+=card[j];
            }
        }
    }for(int i=1;i<=m;i++){
        cout<<num[i]<<' ';
    }

}
