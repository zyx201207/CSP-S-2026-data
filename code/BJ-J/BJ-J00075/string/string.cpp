#include<bits/stdc++.h>
using namespace std;
int n,m,a,ans;
string s,c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    s=" ";
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a >> c;
        for(int j=1;j<=a;j++)
            s+=c;
    }
    m=s.size();
    for(int i=1;i<=m/2;i++){
        if(s[i]!=s[m-i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
