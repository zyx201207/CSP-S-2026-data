#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum,ans;
char c[2000005];
long long b[200005][5];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
        b[i][1]=b[i-1][2]+1;
        b[i][2]=b[i-1][2]+a[i];
    }
    bool flag=0;
    for(int i=1;i<n;i++){
        if(c[i]!=c[i+1]) flag=1;;

    }
    if(flag) cout<<0;
    for(int i=1;i<=(sum+1)/2;i++){
        char l,r;
        if(sum+1-i>=b[n-i+1][1]&&sum+1-i<=b[n-i+1][2]){
            r=c[n+i-1];
        }
        if(i>=b[i][1]&&i<=b[i][2]){
            l=c[i];
        }
        if(l!=r){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
