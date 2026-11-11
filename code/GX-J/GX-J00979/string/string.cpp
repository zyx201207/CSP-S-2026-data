#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in",'r',stdin);
    freopen("string.out",'w',stdout);
    string a;
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        cin>>a;
        for(int j=1;j<=m;j++){
            reverse(a.begin(),a.end());
            cout<<a;
        }
    }



    return 0;
}
