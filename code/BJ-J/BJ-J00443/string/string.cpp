#include<bits/stdc++.h>
using namespace std;
long long n,a,l,ans;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%c",&a,&c);
        l+=a;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    for(int i=0;i<l/2;i++){
        if(s[i]!=s[l-i-1])ans++;
    }
    cout<<ans;
    return 0;
}
