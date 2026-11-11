#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,cnt=0;
int a[N],b[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+1+n,greater<int>());
    if(m==1){
        cout<<a[1];
        return 0;
    }for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            b[i]=max(b[i],int(a[i]&a[j]));
        }cnt=max(cnt,b[i]);
    }cout<<cnt;
    return 0;
}
