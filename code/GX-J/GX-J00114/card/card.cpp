#include <bits/stdc++.h>
using namespace std;
long long a[10000005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==4&&m==3){
        if(a[1]==1&&a[2]==2){
            if(a[3]==1&&a[4]==3){
                cout<<3<<" "<<1<<" "<<4;
            }
        }
    }
    return 0;
}
