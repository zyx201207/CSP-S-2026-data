#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long n,m,a[N],cnt;
int cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    cnt=a[1];
    for(int i=2;i<=m;i++){
        cnt=cnt&a[i];
    }
    cout<<cnt;
    return 0;
}