#include<bits/stdc++.h>;
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n;
    cin>>n;
    long long a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int er[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            er[i][j]=i*j;
        }
    }
    return 0;
}



