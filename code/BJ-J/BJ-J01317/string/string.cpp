#include<iostream>
using namespace std;
#define int long long
int n,ans;
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int aaa;
        char c;
        cin>>aaa;
        cin>>c;
        for(int j=1;j<=aaa;j++){
            s+=c;
        }
    }
    int l=s.size();
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
