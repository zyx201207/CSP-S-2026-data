#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a,sizes,ans;
string s,c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        sizes+=a;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    for(int i=0;i<(sizes-1)/2;i++){
        if(s[i]!=s[sizes-1-i])  ans++;
    }
    cout<<ans;
    return 0;
}
