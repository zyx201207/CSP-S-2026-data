#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

struct node{
    long long a_;
    char c_;
};
node s[100005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long a,l = 0,cnt = 0;
    char c;
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a >> c;
        s[i].a_ = a;
        s[i].c_ = c;
        l += a;
    }
    for (int i = 1;i <= n / 2;i++){
        int j1 = 1,j2 = n;
        char c1 = s[j1].c_,c2 = s[j2].c_;
        if (c1 != c2){
            cnt += min(s[j1].a_,s[j2].a_);
            if (s[j1].a_ > s[j2].a_){
                s[j1].a_ -= s[j2].a_;
                i--;
            }
            else if (s[j1].a_ < s[j2].a_){
                s[j2].a_ -= s[j1].a_;
                i--;
            }
        }
        if (i > n){
            j1++;
            j2--;
        }
    }
    cout << cnt;
    return 0;
}
