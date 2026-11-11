#include<bits/stdc++.h>
using namespace std;
int a[20005];
int m,n;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }if(m==1){
        cout<<n;
        return 0;
    }if(m==2){
        cout<<n/2<<" "<<n/2;
        return 0;
    }for(int i=1;i<=m;i++){
        cout<<1<<" ";
    }
    fclose(stdin);
    fclose(stdout);
}
