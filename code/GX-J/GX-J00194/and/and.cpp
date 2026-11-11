#include<bits/stdc++.h>
using namespace std;
int a[100000],mc[100000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;

    for(int i=1;i<n;i++){
        cin>>a[i];
    }
    int cnt;
    for(int i=1;i<n;i++){
        mc[i]=a[i]%2;
    }
    return 0;
}
