#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int a[N];
long long pos[N];
char c[N];

int main() {

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    long long sum = 0;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i] >> c[i];
        sum += a[i];
        pos[i] = sum;
        //cout << "i" << pos[i] << ' ' << sum << endl;
    }
    //for every a[i], get the position(use binary)
    long long ans = 0;
    for(int i = 1; i <= n; i ++) {
        //pos[i - 1] + 1 ~ pos[i]
        long long r = sum - (pos[i - 1] + 1) + 1;
        long long l = sum - pos[i] + 1;
        //cout << i << '.' << pos[i - 1] << ' ' << pos[i] << "xx\n";
        //cout << i << ' ' << l << ' ' << r << "ilr" << endl;
        //find the position of l:
        //l is in[pos[k - 1] + 1, pos[k]], find k
        int ansl = -1;
        int lx = 1, rx = n + 1;//the range of k:[1, n+1), i.e.[1, n]
        while(rx - lx > 1) {
            int mid = (lx + rx) / 2;
            if(pos[mid - 1] + 1 <= l && pos[mid] >= l) {
                ansl = mid;
                break;
            }
            if(pos[mid - 1] >= l) rx = mid;
            if(pos[mid] < l) lx = mid + 1;
        }
        if(ansl == -1) ansl = lx;
        //cout << "ansl:" << ansl << endl;
        //find the k of r
        int ansr = -1;
        int ly = 1, ry = n + 1;//the range of k:[1, n+1), i.e.[1, n]
        while(ry - ly > 1) {
            int mid = (ly + ry) / 2;
            if(pos[mid - 1] + 1 <= r && pos[mid] >= r) {
                ansr = mid;
                break;
            }
            if(pos[mid - 1] >= r) ry = mid;
            if(pos[mid] < r) ly = mid + 1;
        }
        if(ansr == -1) ansr = ly;
        //cout << "ansr:" << ansr << endl;

        //OK we got it.
        //Then, check if c[i] == c[ansl ~ ansr].
        //Remember that pos[k] is the tail of k-th sub-string.
        //cout << "***";
        for(int j = ansl; j <= ansr; j ++) {
            //cout << "***";
            //cout << i << ' ' << j << endl;
            if(c[i] != c[j]) {
                if(j == ansl && j != ansr) {
                    //cout << "op=1 ";
                    long long x = pos[j];
                    //l~x
                    //cout << l << endl;
                    ans += x - l + 1;
                    //cout << x - l + 1 << ' ' << ans << endl;
                }
                else if(j == ansr && j != ansl) {
                    //cout << "op=2 ";
                    long long x = pos[j - 1] + 1;
                    //x~r
                    ans += r - x + 1;
                    //cout << r - x + 1 << ' ' << ans << endl;
                }
                else if(j == ansr && j == ansl) {
                    //cout << "op=0 ";
                    ans += pos[i] - pos[i - 1];
                    //cout << pos[i] - pos[i - 1] << ' ' << ans << endl;
                }
                else {
                    //cout << "op=3 ";
                    ans += pos[j] - pos[j - 1];
                    //cout << pos[j] - pos[j - 1] << ' ' << ans << endl;
                }
            }
        }
    }

    cout << (ans >> 1);

    return 0;
}
