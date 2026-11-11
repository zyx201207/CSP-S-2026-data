#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int z[N], c[N], b[N];
int n, m, sum, len;
string s;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", z[i]);
        for(int j = 0; j < i; j++){
            if(s[j] - '0' == z[i]){
                for(int k = j; k < i; k++){
                    s[k]--;
                }
                break;
            }
        }
        s[i] = z[i] + '0';
    }
    len = s.size();
    for(int i = 0; i < len; i++){
        c[s[i] - '0' + 1]++;
    }
    sum++;
    while(sum < m){
        sum++;
        for(int i = sum; i < n; i++){
            for(int j = 0; j < i; j++){
                if(s[j] - '0' == z[i]){
                    for(int k = j; k < i