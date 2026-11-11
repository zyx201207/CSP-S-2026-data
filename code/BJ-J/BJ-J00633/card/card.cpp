#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[50010]={};
    int m1[50010]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i1=1;i1<=n;i1++){
            int a1[50010]={},b[50010]={};
            int j=0;
        for(int i=i1;i<=n;i++){
            for(int j1=1;j1<=j;j1++){
                if(a1[j1]==a[i]){
                    for(int z=j1;z<=j;z++){
                        a1[z]=0;
                    }
                }
            }
            j++;
            a1[j]=a[i];
        }
        for(int i=1;i<=j;i++){
            b[a1[i]]++;
        }
        for(int i=1;i<=m;i++){
            if(b[i]) m1[i]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<m1[i]<<" ";
    return 0;
}
