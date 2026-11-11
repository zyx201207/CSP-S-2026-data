#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500000];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        for(int j=n-1;j>=0;j++){
            if(a[j]==i){
                cout<<j<<' ';
            }

        }
    }
    return 0;
}
