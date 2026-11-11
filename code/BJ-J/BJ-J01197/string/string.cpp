#include<bits/stdc++.h>
using namespace std;
const int N = 5e6+5;
char a[N];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    int sz=0;
    for(int i=1; i<=n; i++){
        int x;
        char c;
        cin >> x >> c;
        for(int j=1; j<=x; j++){
            a[i+sz+j]=c;
        }
        sz+=x;
    }
    long long ans=0;
    for(int i=1; i<=sz/2; i++){
        if(a[i]!=a[sz-i+1])ans++;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
