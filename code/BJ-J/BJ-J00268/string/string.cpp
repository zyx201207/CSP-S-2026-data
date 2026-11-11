#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    long long m=0;
    char ch;
    string s;
    scanf("%d", &n);
    for(int i = 1, x;i<=n;i++) {
        cin>>x>>ch;
        m+=x;
        for(int j = 1;j<=x;j++)
            s.push_back(ch);
    }
    long long ans=0;
    for(int i = 0;i<(m+1)/2;i++)
        if(s[i]!=s[m-i-1])
            ans++;
    printf("%lld", ans);
    return 0;   
}
//T2难成啥了