#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n ,a[200000]={},t=0;
    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<a[t];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
