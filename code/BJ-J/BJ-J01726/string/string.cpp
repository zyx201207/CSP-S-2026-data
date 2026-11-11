#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long a,c = 0,ans;
    string x,y;
    char z;
    for (int i = 0;i < n;i++){
        cin >> a >> z;
        for (long long j = 0;j < a;j++){
            x[c] = z;
            c++;
        }
    }
    ans = c - 1;
    for (int i = c;i > 0;i--){
        y[i] = x[c - i];
        if (x[i] == y[i])ans--;
    }
    cout << ans;
    return 0;
}