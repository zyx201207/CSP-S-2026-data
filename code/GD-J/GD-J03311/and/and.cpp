#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }sort(a,a+n,greater<int>());
    ans=a[0];
    for(int i=0;i<m;i++){
        ans&=a[i];
    }cout<<ans;
}