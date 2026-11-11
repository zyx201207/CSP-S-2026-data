#include <bits/stdc++.h>
using namespace std;

int a[2000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,maxd,ym;
    maxd = 0;ym = 0;
    cin >> a[0];
    for(int i = 1;i<n;i++){
        cin >> a[n];
        ym = ym&a[n];
        if(a[n]>maxd){
            maxd = a[n];
        }
    }
    if(m = 1){cout << maxd;}
    else cout << ym;
    return 0;
}