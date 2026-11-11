#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s,ch;
const LL N=2e5+10;
LL a,x,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&a);
    for(LL i=1;i<=a;i++){
        cin>>x;
        cin.get();
        cin>>ch;
        for(LL j=1;j<=x;j++){
            s+=ch;
        }
    }
    for(LL i=0;i<(s.size()-1)/2;i++){
        if(s[i]!=s[s.size()-1-i]){
            ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}

