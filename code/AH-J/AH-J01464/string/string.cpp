#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long a,ans = 0;
    string s;
    string res;
    char c;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a>>c;
        for(long long i = 1;i<=a;i++) s.push_back(c);
    }
    //1
    if(n == 1){
        cout<<0;
        return 0;
    }
    //other
    res = s;
    reverse(res.begin(),res.end());
    if(res == s){
        cout<<0;
        return 0;
    }
    for(int i = 0;i<s.size()/2;i++){
        if(s[i] == s[s.size()-1-i]) continue;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
/*

*/
//CCF please let me AC!
