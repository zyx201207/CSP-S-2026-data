#include<bits/stdc++.h>
using namespace std;
char s[200000];
long long a[200000];
int n;
string ss;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i]>>s[i];
        for(int j = 1;j<=a[i];j++){
            ss += s[i];
        }
    }
    long long l = ss.length();
    for(int i = 0;i<l;i++){
        if(ss[i] != ss[l-i-1]){
            ans++;
            ss[l-i-1] = ss[i];
        }
    }
    cout<<ans;
    return 0;
}
