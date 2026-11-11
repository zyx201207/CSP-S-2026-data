#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long ans = 0,n;
    cin >> n;
    vector<char> S;
    for(int i = 1;i <= n;i++){
        int x;
        char y;
        cin >> x >> y;
        while(x--){
            S.push_back(y);
        }
    }
    for(long long i = 0;i < S.size() / 2;i++){
        if(S[i] != S[S.size() - 1 - i])ans++;
    }
    cout << ans;
    return 0;
}
