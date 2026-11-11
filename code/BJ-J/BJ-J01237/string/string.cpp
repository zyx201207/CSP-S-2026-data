#include<bits/stdc++.h>
using namespace std;
long long n,a,ans,l=-1;
string s;
char t;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>a>>t;
        l+=a;
        while(a--) s+=t;
    }
    for(long long i=0;i<=l/2;i++) if(s[i]!=s[l-i]) ans++;
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
