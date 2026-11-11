#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    long long  my_mo=a[0]&a[1];
    for(int i=2;i<m;i++){
        my_mo&=a[i];
    }
    cout<<my_mo;
    return 0;
}
