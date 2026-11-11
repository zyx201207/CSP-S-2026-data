#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 5;

struct node {
    int num, len;
    bool operator<(node o) const {
        return len > o.len;
    }
};

int n, m, ans;
int a[maxn], tmp[maxn];
vector<node> line;

signed main() {
     freopen("crystal.in", "r", stdin);
     freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    int lst_del = 0, flagB = 1; 
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    	if (i > 1 && lst_del == 0) {
    		lst_del = a[i] - a[i - 1];
		} else {
			if (lst_del != a[i] - a[i - 1]) {
				flagB = 0;
			}
		}
	}
	if (flagB) {
		int cnt = m / lst_del;
		cout << 1 + floor(cnt / 2);
		return 0;
	}
    sort(a + 1, a + n + 1);
    int lst_len = 0, i = 1, flag = 0, tot = 0;
    while (i <= n) {
    	int len = (upper_bound(a + 1, a + n + 1, a[i]) - a) - (lower_bound(a + 1, a + n + 1, a[i]) - a);
//    	cout << a[i] << " " << upper_bound(a + 1, a + n + 1, a[i]) - a << " " << lower_bound(a + 1, a + n + 1, a[i]) - a << "\n";
        line.push_back({a[i], len});
        i += len;
        ++tot;
   		if (lst_len == 0) {
   			lst_len = len;	
		} else {
			if (lst_len != len) {
				flag = 1;
//				cout << lst_len << " " << len << "\n";
			}
		}
    }    
    sort(line.begin(), line.end());
    int num;
    if (flag) {
    	num = line[0].num;
//    	printf("op1 ");
//    	cout << num << " ";
        for (int i = 1; i <= n; ++i) {
            a[i] -= num;
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            if (m - abs(a[i]) >= 0) {
                ++ans;
                m -= abs(a[i]);
            } else {
                cout << ans;
                break; 
            }
        }
	} else {
		if (tot % 2 == 0) {
//			printf("op2 ");
			int ans1 = 0, ans2 = 0;
            int num1 = line[tot / 2].num, num2 = line[tot / 2 + 1].num;
            for (int i = 1; i <= n; ++i) {
                tmp[i] = a[i];
                tmp[i] -= num1;
                a[i] -= num2;
            }
            sort(a + 1, a + n + 1);
            sort(tmp + 1, tmp + n + 1);
            int tmp_m = m, break_flag1 = 0, break_flag2 = 0;
            for (int i = 1; i <= n; ++i) {
                if (m - abs(a[i]) >= 0) {
                    ++ans1;
                    m -= abs(a[i]);
                } else {
                    break_flag1 = 1;
                }
                if (tmp_m - abs(a[i]) >= 0) {
                    ++ans2;
                    tmp_m -= abs(a[i]);
                } else {
                    break_flag2 = 1;
                }
                if (break_flag1 && break_flag2) {
                    cout << max(ans1, ans2);
                    break; 
                }
            }
		} else {
//			printf("op3 ");
			num = line[(tot - 1) / 2].num;
//			cout << num << " ";
            for (int i = 1; i <= n; ++i) {
                a[i] -= num;
            }
            sort(a + 1, a + n + 1);
            for (int i = 1; i <= n; ++i) {
                if (m - abs(a[i]) >= 0) {
                    ++ans;
                    m -= abs(a[i]);
                } else {
                    cout << ans;
                    break; 
                }
            }
		} 
	}
    return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
