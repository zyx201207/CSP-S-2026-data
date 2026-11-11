#include<bits/stdc++.h>
using namespace std;
long long n,a[20005],ans=0,f=0;
char c[20005];
string l;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(long long i=1;i<=n;i++){
            f+=a[i];
        for(long long j=1;j<=a[i];j++){
            l+=c[i];
        }
    }
    for(long long i=0;i<f/2;i++){
        if(l[i]!=l[f-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
