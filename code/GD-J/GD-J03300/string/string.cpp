#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
ll n;
string str="";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin>>n;
    while(n--){
        ll a;
        char c;
        cin>>a>>c;
        for(int i=1;i<=a;i++)
            str+=c;
    }
    ll sz=str.size(),cnt=0;
    for(ll i=0;i<=sz/2-1;i++){
        if(str[i]!=str[sz-1-i])
            cnt++;
    }
    cout<<cnt;
    return 0;
}
