#include<bits/stdc++.h>
using namespace std;
long long a[100010],n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }else if(m==2){
        cout<<a[n-1];
        return 0;
    }else{
        cout<<a[n-m+1];
        return 0;
    }
    return 0;
}
