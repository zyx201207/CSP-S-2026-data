#include<iostream>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500001],b[500001];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]=i;
    }
    if(m==1){
        cout<<n;
        return 0;
    }
    for(int i=1;i<=m;i++){
      cout<<b[i]<<" ";
    }
    return 0;
}
