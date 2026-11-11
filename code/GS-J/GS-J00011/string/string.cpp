#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll a;
    char c;
}s[200005];
ll q[200005];
ll sum;
int n,l = 1,r = 0,li = 1,ri;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%lld %c",&s[i].a,&s[i].c);
        r += s[i].a;
        q[i] = q[i-1] + s[i].a;
    }
    if(q[n] > 10000000){
        cout << q[n]/2;
        return 0;
    }
    ri = n;
    while(l < r){
        if(l > q[li]) li++;
        if(r < q[ri-1]) ri--;
        if(s[li].c != s[ri].c) sum++;
        l++;
        r--;
    }
    cout << sum;
    return 0;
}
