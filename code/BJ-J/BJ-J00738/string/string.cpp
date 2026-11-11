#include <bits/stdc++.h>
using namespace std;

const int N = 2 *1e5 + 5;;
typedef long long ll;
int n, m, a[N];
char c[N];
ll cnt1[50], cnt2[50], sum[N];
vector<char> arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ll ans = 0;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        sum[i] = sum[i - 1] + a[i];
        for(int j = 1; j <= a[i]; j++){
            arr.push_back(c[i]);
        }
        //cout << sum[i] << " " ;
    }

    //ll mid = sum[n] / 2;
    //mid = upper_bound(sum + 1, sum + n + 1, mid) - sum - 1;
    //int l = 1, r = n, mid = 0;
    //while(l > r) {
    //    int mid = (l + r) / 2;
     //   if(sum[mid] > mi) {
    //        r = mid + 1;
     //   } else {
     //       l = mid;
    //    }
    //}
    //cout << mid << endl;

    //l//l tmp = 0, idx = 0;
    //for(idx = 1; idx <= n; idx++) {
     //   if(tmp + a[idx] > mid) break;
     //   tmp += a[idx];
    //}//
    //cout << idx << endl;
    //for(int i = 1; i < idx; i ++) {
    //    cnt1[c[i] - 'a' + 1] += a[i];
    //}

    //cout << mid - sum[idx - 1] << " " << sum[idx] - mid << endl;

    //cnt1[c[idx] - 'a' + 1] += mid - sum[idx - 1];
    //cnt2[c[idx] - 'a' + 1] += sum[idx] - mid - (sum[n] % 2 == 0 ? 0 : 1);
    //for(int i = idx + 1; i <= n; i ++) {
     //   cnt2[c[i] - 'a' + 1] += a[i];
    //}
    //for(int i = 1; i <= 26; i ++) {
    //   cout << cnt1[i] << " ";
    //}
    //cout << endl;
    //(int i = 1; i <= 26; i ++) {
    //   cout << cnt2[i] << " ";
    //}

    //for(int i = 1; i <= 31; i++) {
    //    ans += abs(cnt1[i] - cnt2[i]);
    //}
    for(int i = 1; i <= arr.size() / 2; i++) {
        if(arr[i] != arr[arr.size() - 1]) {
            ans++;
        }
    }

    cout << ans <<endl;

    return 0;
}
