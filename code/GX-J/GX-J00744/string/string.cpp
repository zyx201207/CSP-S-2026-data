#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    long long n,a,q;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>a>>s;
        for(int j=1;j<=a;j++){
            s=""+s;
        }
    }
    long long z=s.length()-1;
    for(int i=0;i<=z;i++){
        if(s[i]!=s[z-i]){
            q++;
        }
    }
    cout<<q;
    return 0;
}
