#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long qz[200005];
char b[200005];
long long n;
int q(long long x){
    int l=1,r=n;
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(x<=qz[mid]&&x>qz[mid-1]){
            return mid;
        }else if(x>qz[mid]){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    qz[0]=0;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        qz[i]=qz[i-1]+a[i];
    }
    long long cnt=0;
    for(long long i=1;i<=qz[n]/2;i++){
        if(b[q(i)]!=b[q(qz[n]+1-i)]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
