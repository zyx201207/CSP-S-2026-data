#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool c(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n,c);
    int cnt=a[1];
    for(int i=1;i<=n;i++){
        cnt=cnt&a[i];
    }
    cout<<cnt;
    return 0;
}
