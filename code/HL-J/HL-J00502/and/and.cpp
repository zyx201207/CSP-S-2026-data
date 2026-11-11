#include<bits/stdc++.h>
using namespace std;
long long a[2000000]={},b[2000000]={};
long long n,m,d,p=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>=m;i--){
        b[p]=a[i];
        p++;
    }

    d=b[0]&b[1];
    cout<<d;





    return 0;
}

