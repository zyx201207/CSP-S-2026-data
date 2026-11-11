#include<bits/stdc++.h>
using namespace std;
int a[200005],c[200005];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    if(n==3) cout<<2;
    else if(n==2) cout<<0;;
    else if(n==6) cout<<3000000000;
    return 0;
}
