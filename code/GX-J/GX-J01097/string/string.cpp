#include<bits/stdc++.h>
using namespace std;
int sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("strinhg.out","w",stdout);
    long long n,a[200005];
    char c[200005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }for(int i=0;i<n;i++){
        if(c[i]!=c[n-1-i]){
            c[n-1-i]=c[i];
            sum++;
        }
        if(a[i]!=a[n-1-i]){
            a[i+1]+=a[n-1-i]-a[i];
            sum+=a[n-1-i]-a[i];
            a[n-1-i]=a[i];
        }
    }cout<<sum;
    return 0;
}
