#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);


    int n,m;
    cin>>n>>m;
    int a[1005]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<a[n];

    fclose(stdin);
    fclose(stdout);
    return 0;
}
