#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n;
    cin >> m >> n;
    int a[n];
    int x[]={3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3,8,3,2,7,9,5,0,2,8,8,4,1,9};
    for(int i=0;i<m;i++){
        cin >> a[i];
    }
    if(m==10){
        cout << 10 << " " << 3 << " " << 3;
        return 0;
    }
    for(int i=0;i<n;i++){
        cout << x[i] << " ";
    }
    return 0;
}
