#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b;
int n,ans;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int m;
        char c;
        cin>>m>>c;
        for(int j=1;j<=m;j++){
            a+=c;
        }
    }
    for(int i=a.size()-1;i>=0;i--){
        b+=a[i];
    }
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i])
            ans++;
    }
    cout<<(ans%2==0?ans/2:ans/2+1);
    return 0;
}