#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000010];
int cnt=1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    cnt=a[1];
    for(int i=1;i<=m;i++){
        cnt=(cnt&a[i]);
    }
    cout<<cnt;
    return 0;
}
