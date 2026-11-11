#include <bits/stdc++.h>
using namespace std;

long long a[200010], n;
char c[200010];

long long calc(bool flag, long long strsize){
    long long cur = 0, num = 0, ncur = 0, nnum = 0, ans = 0;//cur是用到第几个字符串了 num是用到字符串的第几位了
    cur = 1; num = a[1]; ncur = n; nnum = a[n];
    for(long long i = 1; i <= strsize / 2; ){// i为总字符串的进度
        //cout << "循环第" << i << "次\n";
        if(c[cur] == c[ncur]){
            i += min(num, nnum);
            if(num < nnum){
                nnum -= num;
                cur++; num = a[cur];
            }
            else if(num == nnum){
                cur++; num = a[cur];
                ncur--; nnum = a[ncur];
            }
            else{
                num -= nnum;
                ncur--; nnum = a[ncur];
            }
            if(cur >= ncur){
                return ans;
            }
        }
        else{
            ans += min(num, nnum);
            i += min(num, nnum);
            if(num < nnum){
                nnum -= num;
                cur++; num = a[cur];
            }
            else if(num == nnum){
                cur++; num = a[cur];
                ncur--; nnum = a[ncur];
            }
            else{
                num -= nnum;
                ncur--; nnum = a[ncur];
            }
            if(cur >= ncur){
                return ans;
            }

        }

        //cout << cur << " " << ncur << " " << num << " " << nnum << "\n";

        /*
        ans += (c[cur] != c[ncur]);
        nnum++; num++;
        if(nnum > a[ncur]){
            ncur--;
            nnum = 1;
        }
        if(num > a[cur]){
            cur++;
            num = 1;
        }
        */
    }

    return ans;

}

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long ss = 0; cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        ss += a[i];
    }

    cout << calc(0,ss);
    return 0;
}
