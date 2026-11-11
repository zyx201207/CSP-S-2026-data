#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[20000005],len=0,ans=0;
string c[20000005];
string s="";
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
        for(int j=1;j<=a[i];j++){
            s+=a[i];
        }
    }
    int i;
    if(len%2==1) i=len/2+1;
    else i=len/2;
    for(i=i-1;i<len;i++){
        if(s[i]!=s[len+1-i]){
            ans++;
            //cout<<i<<' '<<s[len+1-i]<<s[i]<<endl;
        }
    }
    cout<<ans;
    return 0;
}
