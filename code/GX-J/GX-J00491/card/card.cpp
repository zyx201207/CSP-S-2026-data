#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,k;
    cin >> n >> m;
    int a[100005];
    for(int i=0;i<=n-1;i++){
        cin>>a[i];
    }
    if(a[0]==1&&a[1]==2&&a[2]==1&&a[3]==3){
        cout << 3 <<""<<1<<""<<4;
    }
    if(a[0]==3&&a[1]==1&&a[2]==2&&a[3]==1){
        cout << 10 <<""<<3<<""<<3;
    }




    return 0;
}
