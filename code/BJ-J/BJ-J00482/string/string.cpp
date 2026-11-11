#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt, ans;
string s;
int main(){
    /*
    zhe ti TLe
    zhi neng na 48 fen
    */
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x>>c;
        cnt+=x;
        for(int j=1;j<=x;j++)s+=c;
    }

    for(long long i=0;i<cnt/2;i++){
        if(s[i]!=s[cnt-i-1])ans++;
    }
    cout<<ans;
    return 0;
}
