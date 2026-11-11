#include<bits/stdc++.h>
using namespace std;
int a[210000];
int x(int n){
    int cnt=0;
    for(;n>0;n&(n-1),cnt++)
    return cnt;
}
bool cmp(int n1,int n2){
    return x(n1)>x(n2)||(x(n1)==x(n2)&&n1>n2);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    long long ans=INT_MAX;
    for(int i=1;i<=m;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
