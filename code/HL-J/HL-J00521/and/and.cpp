#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],b[N],ans;
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
    for(int i=1;i<=m;i++){
        b[i]+=a[i];
    }
    for(int i=1;i<=1;i++){
        cout<<b[m];
    }
    return 0;
}
