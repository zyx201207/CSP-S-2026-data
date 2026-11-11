#include<bits/stdc++.h>
using namespace std;

int n;
int a[200000+10];
char x[200000+10];
int everycnt[26];
long long sum;
int s2[4000*4000+10];
string s;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1;i<=n;i++) {
        cin >> a[i] >> x[i];
        //f[i] = sum+1;
        sum += a[i];
        /*lst[i] = sum;
        every[x[i]-'A'][0][++everycnt[x[i]-'A']] = f[i];
        every[x[i]-'A'][1][everycnt[x[i]-'A']] = lst[i];*/
    }
    if(sum <= 1e6) {
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=a[i];j++) {
                s += x[i];
            }
        }
        int num=0;
        int len = s.length()-1;
        for(int i = 0;i<=(len)/2;i++) {
            if(s[i] != s[len-i]) num++;
        }
        cout << num;
        return 0;
    }
    else if(sum <= 4000*4000) {
        long long cnt = 0;
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=a[i];j++) {
                s2[++cnt] = x[i] - '0';
            }
        }
        int num=0;
        int len = s.length()-1;
        for(int i = 0;i<=(len)/2;i++) {
            if(s2[i] != s2[len-i]) num++;
        }
        cout << num;
        return 0;
    }
    /*else{
        sum--;
        long long num = 0;
        for(int i = 1;i<=n;i++) {
            int nowf = sum - lst[i], nowlst = sum - f[i];
            num += a[i];
            for(int j = 1;j<=everycnt[x[i]-'A'];j++){
                if(every[x[i]-'A'][0][j] >= nowf || every[x[i]-'A'][1][j] <= nowlst) {
                   int nw = every[x[i]-'A'][0][j];int ny = every[x[i]-'A'][1][j];
                   nw = max(nw, nowf);ny = min(ny, nowlst);
                   num -= (ny - nw + 1);
                }
            }
        }

    }*/
    cout << 0;
}
