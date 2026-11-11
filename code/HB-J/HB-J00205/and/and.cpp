#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int nm,be=0;
int main(){
    freopen("and.in","r".stdin);
    freopen("and.out","w".stdout);
    cin>>nm>>be;
    int a[N]=0;
    for(int i=1;i<=nm;i++){
        cin>>a[i]>>a[i];
    }
    cout<<a[2];
    return 0;
}
