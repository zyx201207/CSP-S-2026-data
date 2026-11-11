#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
typedef long long ll;
ll n , a[N] , sum = 0 , cnt = 0 , ans = 0 ,an=0;
char c[N];
string s,s_;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i =1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
        for(ll j=0;j<a[i];j++){
            s+=c[i];
        }
    }
    if (n == 1) cout<<0;
    s_=s;
    reverse(s.begin(),s.end());
    for(ll i=0;i<sum;i++){
        if(s[i]!=s_[i]) cnt++;
    }
    cout<<cnt/2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
