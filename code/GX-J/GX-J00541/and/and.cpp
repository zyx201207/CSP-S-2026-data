#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200000],ans=256*256*256*256*256;
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
    sort(a+1,a+1+n,cmp);
    int x=1;
    for(int i=2;i<m;i++){
        ans=ans&a[i-1];
    }
    cout<<ans;
    return 0;
}

