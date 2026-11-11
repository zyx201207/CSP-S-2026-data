#include <bits/stdc++.h>
using namespace std;

struct node{
    long long num;
    char c;
}s[200005];

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin >> n;
    for(long long i = 1; i <= n; i ++) {
        cin >> s[i].num >> s[i].c;
    }
    long long r = 1,l = n,sum = 0;
    while(r < l) {
        if(s[r].c == s[l].c) {
            if(s[r].num > s[l].num) {
                s[r].num -= s[l].num;
                s[l].num = 0;
                l --;
            }
            else if(s[r].num == s[l].num) {
                r++;
                l--;
            }
            else {
                s[l].num -= s[r].num;
                s[r].num = 0;
                r++;
            }
        }
        else {
            if(s[r].num > s[l].num) {
                sum += s[l].num;
                s[r].num -= s[l].num;
                s[l].num = 0;
                l --;
            }
            else if(s[r].num == s[l].num) {
                sum += s[r].num;
                r++;
                l--;
            }
            else {
                sum += s[r].num;
                s[l].num -= s[r].num;
                s[r].num = 0;
                r++;
            }
        }
    }
    printf("%lld",sum);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

