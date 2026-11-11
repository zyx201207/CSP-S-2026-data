#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a[200005]={},cnt=0,ans=0;
    long long n;
    long long m;
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cnt=a[n-m];
    cout<<cnt<<endl;
    return 0;
}
