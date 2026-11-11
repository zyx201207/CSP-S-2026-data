#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[10000],a1[10000],m1[1000];
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
        a1[i] = a[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            a1[j] = a[j];
        }
        cout << a[j];
    }
}
