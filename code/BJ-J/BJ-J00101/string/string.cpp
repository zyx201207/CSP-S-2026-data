#include<iostream>
#include<stack>
using namespace std;
typedef long long ll;
ll n,pos=0,l,r,ans;
char s[20000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        ll a;
        char c;
        cin>>a>>c;
        r+=a;
        while(a--)s[pos++]=c;
    }
    r--;
    while(l<r){
        if(s[l]!=s[r])ans++;
        l++;r--;
    }
    cout<<ans;
    return 0;
}

