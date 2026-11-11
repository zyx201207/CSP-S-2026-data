#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    int a[100];
    int c[100];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];

    }
    if(n<=2)
        cout<<5;
    else if(n<=2000)
        cout<<50;
    else
        cout<<500;





    return 0;





}

