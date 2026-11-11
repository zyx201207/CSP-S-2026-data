#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
    long long cnt;
    int a;
}k[200007],k1[200007],k2[200007];
long long ans = 0;
long long tot = 0,pos1,pos2,m = 0;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> k[i].cnt >> s;
        k[i].a = (s[0] - 'a' + 1);
        m += k[i].cnt;
    }
    m /= 2;
    tot = 0;
    for(int i = 1;i <= n;i++){
        if(tot + k[i].cnt >= m){
            k1[i].cnt = m - tot;
            k1[i].a = k[i].a;
            //cout << k1[i].cnt << endl;
            break;
        }
        k1[i].cnt = k[i].cnt;
        k1[i].a = k[i].a;
        tot += k[i].cnt;
        //cout << k1[i].cnt << " ";
    }
    tot = 0;
    for(int i = 1;i <= n;i++){
        if(tot + k[n - i + 1].cnt >= m){
            k2[i].cnt = m - tot;
            k2[i].a = k[n - i + 1].a;
            //cout << k2[i].cnt << endl;
            break;
        }
        k2[i].cnt = k[n - i + 1].cnt;
        k2[i].a = k[n - i + 1].a;
        tot += k[n - i + 1].cnt;
        //cout << k2[i].cnt << " ";
    }
    pos1 = 1,pos2 = 1;
    while(k1[pos1].a != 0 || k2[pos2].a != 0){
        if(k1[pos1].cnt == k2[pos2].cnt){
            if(k1[pos1].a != k2[pos2].a)ans += k1[pos1].cnt;
            pos1++;
            pos2++;
        }
        else if(k1[pos1].cnt > k2[pos2].cnt){
            if(k1[pos1].a != k2[pos2].a)ans += k2[pos2].cnt;
            k1[pos1].cnt -= k2[pos2].cnt;
            pos2++;
        }
        else if(k1[pos1].cnt < k2[pos2].cnt){
            if(k1[pos1].a != k2[pos2].a)ans += k1[pos1].cnt;
            k2[pos2].cnt -= k1[pos1].cnt;
            pos1++;
        }
    }
    cout << ans;
    return 0;
}
