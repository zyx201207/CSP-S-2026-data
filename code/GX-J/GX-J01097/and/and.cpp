#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }sort(a,a+n,cmp);
    int maxa=a[0];
    for(int i=1;i<m;i++)maxa&=a[i];
    cout<<maxa;
    return 0;
}
