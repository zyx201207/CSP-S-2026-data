#include<bits/stdc++.h>
using namespace std;
int n,m,p,num;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int aa[n];
    for(int u=0;u<n;u++){
        for(int i=u;i<n;i++){
        cin>>aa[i];
        for(int j=i;j>=0;j++){
            if(aa[i]==aa[j]){
                p=i;
            }
        }


        for(int i=1;i<=m;i++){
        for(int j=p;j<n;j++){
            if(aa[j]==i){
                num+=1;
                break;
            }
        }

    }

    }cout<<num<<" ";

    }

    return 0;
}
