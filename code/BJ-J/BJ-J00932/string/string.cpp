#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,sum,ans;
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        string y;
        cin >> x >> y;
        sum+=x;
        for(int j=1; j<=x; j++)s+=y;
    }
    string a,b;
    if(sum%2==1){
        for(int i=0; i<s.size()/2+1; i++){
            a[i]=s[i];
            b[i]=s[s.size()-1-i];
        }
        for(int i=0; i<s.size()/2+1; i++){
            if(a[i]!=b[i])ans++;
        }
        cout << ans;
    }
    else{
        for(int i=0; i<s.size()/2; i++){
            a[i]=s[i];
            b[i]=s[s.size()-1-i];
        }
        for(int i=0; i<s.size()/2; i++){
            if(a[i]!=b[i])ans++;
        }
        cout << ans;
    }
}
