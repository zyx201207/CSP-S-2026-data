#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, l = 1, a[200005], b[200005], s[200005], cnt = 1, x, y, lf, ans, fl, e;
char ch;

int main(){
    freopen("string.in" , "r", stdin );
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    e = n;
    s[1] = l;
    cin >> x >> ch;
    a[1]+=x;
    b[1] = (int)ch-'a';
    l+=x;
    for(int i = 2; i <= n; i++){
        cin >> x >> ch;
        y = (int)ch-'a';
        //cout << y;
        if(y == b[cnt]){
            a[cnt]+=x;
        }else{
            cnt++;
            a[cnt] +=x;
            b[cnt] = y;
            s[cnt] = l;
        }
        l+=x;
    }
    //cout << s[1] << " " << s[2] << " " << s[3];
    l--;
    b[n+1] = b[1];
    for(int i = 1; i <= cnt; i++){
        if(b[i] != b[e+1] && a[i] >= lf){
            ans+=lf;
            s[i]+=lf;
            a[i]-=lf;
        }else if(b[i] != b[e+1] && a[i] < lf){
            lf-=a[i];
            ans+=a[i];
            continue;
        }
        ll ed = s[i]+a[i]-1;
        ll st = upper_bound(s+1, s+1+cnt, l-ed+1)-s-1;
        if(st < i) break;
        //cout << ed;
        //cout << s[3];
        lf = l-ed+1 - s[st];
        for(int j = st+1; j <= e; j++){
            if(b[i] != b[j]) ans+=a[j];
        }
        //cout << ans;
        if(b[i] != b[st]) ans+=a[st]-lf;
        e = st-1;
        //cout << st << " " << ans << " " << lf << endl;
    }
    cout << ans;
    return 0;
}
