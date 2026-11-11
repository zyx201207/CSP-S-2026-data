#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,len,cnt;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x>>c;
        for(int j=1;j<=x;j++) s+=c;
    }
    len=s.size();
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1]) cnt++;
    }
    cout<<cnt;
    return 0;
}
