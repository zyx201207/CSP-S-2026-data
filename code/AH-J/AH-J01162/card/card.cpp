#include<bits/stdc++.h>
using namespace std;
int a[50005];
int main(){
    int m,n;
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>m>>n;
    int i;
    for(i=1;i<=m;i++)cin>>a[i];
    for(int j=1;j<=i;j++){
        if(a[i]==a[j]){
            for(int k=1;k<=j;k++) a[k]=-1;
        }
    }
    for(int ii=1;ii<=i;ii++){
        if(a[ii]>0){
        cout<<a[ii]<<" ";
        }
    }
}
