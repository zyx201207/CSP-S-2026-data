#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and5.in","r",stdin);
    freopen("and.out","w",stdout);
    long long int n,m;
    cin>>n>>m;
    vector<long long int> a(n);
    for(long long int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<long long int>());
    long long sum=2147483648*2147483648-1;
    for(long long int i=0;i<m;i++){
        sum&=a[i];
    }
    cout<<sum;
    return(0);
}