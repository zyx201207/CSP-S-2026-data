#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
long long n;
char cz(int x){
    for(int i=1;i<=n;i++){
        if(a[i]>=x){
            return c[i];
        }
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long cnt=0;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        cnt+=a[i];
        a[i]+=a[i-1];

    }
    long long l,r;
    l=1;
    r=cnt;
    long long ans=0;
    while(l<=r){
        if(cz(l)!=cz(r)){
            ans++;
        }
        l++;
        r--;
    }
    cout<<ans;
    return 0;
}