#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in",'r',stdin);
    freopen("and.out",'w',stdout);
    int a[1000005];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=m;j++){
            int cnt=a[j]+a[j+1];
            cout<<cnt<<' ';
        }
    }


    return 0;
}
