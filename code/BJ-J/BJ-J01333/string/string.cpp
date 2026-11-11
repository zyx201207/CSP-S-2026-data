#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(0);cin.tie(0);
    int n;
    cin >>n;
    string s;
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        int m;
        cin >>m;
        char a;
        cin >>a;
        for(int j = cnt + 1;j <= cnt + m;j++){
            s[j] = a;
        }
        cnt += m;
    }
    int ans = 0;
    for(int i = 1;i <= cnt / 2;i++){
        if(s[i] != s[cnt+1-i]){
            ans++;
        }
    }
    cout <<ans;
}
