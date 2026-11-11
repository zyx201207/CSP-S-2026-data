#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
string s;
int n;
long long ans = 0;
void check(){
    int x = n;
    for(int i = 0;i<=s.size()-i-1;i++){
        if(s[i]!=s[s.size()-i-1]){
            ans++;
        }
    }
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>n;
    for(int i = 1;i<=n;i++){
        int x;
        char a;
        cin >> x>>a;
        for(int i = 1;i<=x;i++){
            s+=a;
        }

    }
    check();
    cout <<ans;
    return 0;
}
