#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a,ans;
string c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    while(n>=0){
        ll ans=0;
        cin >> a;
        cin >> c;
        ans+=a;
        if(n==1){
            if(ans%2==1)
                ans=ans/2+1;
            else if(a%2==0)
                ans=ans/2;
            cout << ans;
        }
        n--;
        if(c==c)
            ans+=0;
    }
}
