#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
ll n,a,l,ans;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    s=" ";
    cin>>n;
    while(n--){
        cin>>a>>c;
        l+=a;
        while(a--)s.push_back(c);
    }
    if(l%2){
        ll z=(l+1)/2-1,y=(l+1)/2+1;
        for(;z>=1;z--,y++)if(s[z]!=s[y])ans++;
    }
    else{
        ll z=l/2,y=l/2+1;
        for(;z>=1;z--,y++)if(s[z]!=s[y])ans++;
    }
    cout<<ans;
    return 0;
}
