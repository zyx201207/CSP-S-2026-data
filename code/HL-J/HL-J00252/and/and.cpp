#include<bits/stdc++.h>
using namespace std;
long long a[10000008];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ma=0,q=0;
    cin >> n >>m;
    for(int i=1;i<=n;i++){

            cin >> a[i];

    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            q=a[j] and a[j+1];
            ma=max(ma,q);
        }
    }
    cout << ma;


    return 0;
}

