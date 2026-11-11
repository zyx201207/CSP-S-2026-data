#include<bits/stdc++.h>
using namespace std;

long long n;
string s;
long long ans=0;
long long len=0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        long long a;
        char c;
        cin >> a >> c;
        len=len+a;
        for(int j=1;j<=a;j++){
            s=s+c;
        }
    }
    string q;
    string h;
    for(int i=0;i<len/2;i++){
        q=q+s[i];
    }
    for(int i=len-1;i>len/2;i--){
        h=h+s[i];
    }
    for(int i=0;i<len/2;i++){
        if(q[i]!=h[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
