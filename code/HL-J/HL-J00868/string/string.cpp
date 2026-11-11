#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
int ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        cin >>c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }

    }
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-i-1]){}
        ans++;
    }
    ans/=2;
    int tot=0;
    for(int i=s.size()-1;i>=0;i--){
        if(s[s.size()-i-1]!=s[i]){
            tot++;
        }

    }
    tot/=2;
    cout << min(ans,tot);
    return 0;
}
