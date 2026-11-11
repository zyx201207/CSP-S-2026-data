#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[200005]={},cnt=0;
    char b[200005]={};
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }for(int i=n-1;i>=0;i--){
        if(b[i]!=b[1]){
            b[i]=b[i];
        }
        cnt+=a[i];
    }
    cout<<cnt;
    return 0;
}
