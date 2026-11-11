#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, asum;
struct st{
    int s, e, l;
    char c;
    st(){};
    st(int p1, int p2, int p3, char p4){
        s = p1; e = p2; l = p3; c = p4;
    };
}a[200005];
signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n; asum=0;
    if(n == 1){
        cout << 0; return 0;
    }
    for(int i=0;i<n;i++){
        int tmp1; char tmp2; cin >> tmp1 >> tmp2;
        a[i].s = asum+1; asum += tmp1; a[i].e = asum; a[i].l = tmp1;
        a[i].c = tmp2;
    }
    if(asum % 2 == 0){
        asum += 1; int tpos = (asum - 1) / 2;
        for(int i=0;i<n;i++){
            if(a[i].e >= tpos){
                for(int j=n-1; j > i; j--) a[j+2] = st(a[j].s, a[j].e, a[j].l, a[j].c);
                a[i+1] = st(tpos+1, tpos+1, 1, a[i].c);
                a[i+2] = st(tpos+2, a[i].e, a[i].e-tpos-1, a[i].c);
                a[i] = st(a[i].s, tpos, tpos-a[i].s + 1, a[i].c);
                break;
            }
        }
        n += 2;
    }
    int pos = (asum + 1) / 2; int ans = 0;
    stack<st> st1, st2;
    for(int i=0;i<n;i++){
        if(a[i].s <= pos && a[i].e >= pos){
            for(int j=0;j<i;j++) st1.push(a[j]);
            if(a[i].s != pos) st1.push(st(a[i].s, pos-1, pos - a[i].s, a[i].c));

            for(int j=n-1;j>i;j--) st2.push(a[j]);
            if(a[i].e != pos) st2.push(st(pos+1, a[i].e, a[i].e - pos, a[i].c));

            break;
        }
    }
    while(!st1.empty() && !st2.empty()){
        st t1 = st1.top(); st t2 = st2.top();
        if(t1.l >= t2.l){
            st2.pop(); st1.pop();
            if(t1.l-t2.l > 0) st1.push(st(t1.s, t1.e-t2.l, t1.l-t2.l, t1.c));
            ans += (t1.c == t2.c ? 0 : t2.l);
        }else{
            st1.pop(); st2.pop();
            st2.push(st(t1.s+t1.l, t1.e, t2.l-t1.l, t2.c));
            ans += (t1.c == t2.c ? 0 : t1.l);
        }

    }

    cout << ans;

    return 0;
}
