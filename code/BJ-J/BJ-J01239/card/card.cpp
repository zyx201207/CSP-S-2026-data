#include<bits/stdc++.h>
using namespace std;
int n,m,ds[1005],ac=0,bc=0,ca=0,cb=0,k=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>ds[i];
    }
    while(k<=n){
        for(int i=k-1;i<n;i++){
            if(ds[i]==1){
                ac++;
            }
            if(ds[i]==2){
                bc++;
            }
            if(ac%2==0){
                ac=1;
                if(bc%2==1){
                    bc--;
                }
            }
            if(bc%2==0){
                bc=1;
                if(ac%2==1){
                    ac--;
                }
            }
        }
        if(ac==1){
            ca++;
            cout<<k<<" "<<ca<<" "<<ac<<endl;
            ac=0;
        }
        if(bc==1){
            cb++;
            cout<<k<<" "<<cb<<" "<<bc<<endl;
            bc=0;
        }
        k++;
    }
    cout<<ca<<" "<<cb;
    return 0;
}
