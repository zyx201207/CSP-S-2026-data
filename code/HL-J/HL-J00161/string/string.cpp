//max a[i]<=500 n<=2*10^5
#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int a[MAXN];
char c[MAXN];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long L=0;
    string s;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
        L+=a[i];
        for(int j=1;j<=a[i];j++){
            s.push_back(c[i]);
        }
    }
    long long ans=0;
    for(int i=1;i<=L/2;i++){
        if(s[i-1]!=s[L-i]) ans++;
    }


    cout << ans << '\n';
    return 0;
}
