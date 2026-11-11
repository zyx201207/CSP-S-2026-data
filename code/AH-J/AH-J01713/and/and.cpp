#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return y>x;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,a[100001],m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);

    cout<<a[n-m];
    return 0;
}

