#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200010];
char c[200010];
string b,d;
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        int s=b.size();
        for(int j=s;j<s+a[i];j++){
            b+=c[i];
        }
    }
    d=b;
    for(int i=0,j=b.size()-1;i<=b.size()/2;i++,j--){
        if(d[j]!=b[i]){
            d[j]=b[i];
            ans++;
        }
    }
    cout<<ans<<"\n";

    return 0;
}
