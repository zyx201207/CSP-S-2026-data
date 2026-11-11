#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
const int M = 3e5+10;int n,m;
int a[N] = {},cnt[M] = {},s[M] = {};//s[i]表示数字i出现的个数（输出）
void by(int num,int c) {
    s[a[num]] += c;
    if(num == n) {
        return;
    }
    by(last[a[num+1]],c);

            //return cnt[a[num]]+by(num+1);
}
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        cnt[a[i]]++;
        last[a[i]] = i;
    }
    for(int i = n;i >= 1;i--) {
        if(!s[a[i]]) {
            by(i,cnt[a[i]]);
        }
    }
    for(int i = 1;i<=m;i++) cout<<s[i]<<' ';
    return 0;
}
