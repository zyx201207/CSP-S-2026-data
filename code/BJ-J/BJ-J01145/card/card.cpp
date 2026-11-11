#include<bits/stdc++.h>
using namespace std;
int a[100];
int b[100];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w,"stdout);
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
 for(int i=1;i<=n;i++){
    if(b[sum]!=a[i]){
        b[i]=a[i];
        sum=i;
    }
    
    if(b[sum]==a[i]){
        i++;
        sum==i
    }
 }
 for(int i=1;i<=m;i++){
        
    cout<<a[sum]<<" ";
 }
        

    return 0;
}
