#include<bits/stdc++.h>
using namespace std;
const long long N=1e5*2;
long long n,l=0;
string s;
long long z,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char a;
        cin>>x>>a;
        for(int j=1;j<=x;j++){
            s+=a;
        }
        l+=x;
    }
    z=l/2;
    for(int i=1;i<=z;i++){
        if(s[l-i+1]!=s[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
