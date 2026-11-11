#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    a[n]=n;
    a[n+1]=m;
    sort(a,a+n+2,greater<int>());
    for(int i=0;i<m;i++){
        cout<<a[i]<<' ';
    }
    return 0;
}
