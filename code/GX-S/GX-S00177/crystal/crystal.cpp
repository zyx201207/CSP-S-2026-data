#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,p=0;
    cin>>n>>m;
    int a[500001];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long ans=n,i=0,j=n-1;
    while(i<=j){
        if(abs(a[j]-a[i])<=m){
            cout<<ans-i;
            break;
        }
        i++;
        j--;
    }
    return 0;
}
