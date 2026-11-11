#include<bits/stdc++.h>
using namespace std;
int k;
struct n{
    int len;
    char a;
} S[200005];
int s[200005];
char get(int idx){
    for(int i = 1; i <= k; i++){
        if (idx > s[i - 1] && idx <= s[i]) return S[i].a;
    }
    return ' ';
}
int main(){
    freopen("string.in", "r",stdin);
    freopen("string.out", "w",stdout);

    cin >> k;
    for (int i = 1; i <= k; i++){
        cin >> S[i].len >> S[i].a;
        s[i] = s[i-1] + S[i].len;
    }
    int p = 1;
    int sum = 0;
    for (int i = 1; i <= s[k]/2; i++){
        if (get(i) != get(s[k] - i + 1)) sum++;
    }
    cout << min(sum, s[k] - sum);
    return 0;
}
