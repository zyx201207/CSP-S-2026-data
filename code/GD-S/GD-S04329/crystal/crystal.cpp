#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a;
vector<int> c = {0};
int b;
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    bool f = 1;
    int ls = 0;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        a.push_back(t);
        if(f) {
        	if(i == 1)
        		continue;
        	if(i == 2) {
        		ls = t - a[i - 2];
			}else {
				if(ls != t - a[i - 2])
					f = 0;
			} 
		}
    }
    if(f) {
    	for(int i = 0; i <= m; i++) {
    		if(((i + 1) * i) / 2 * ls > m) {
    			cout << i;
    			break;
			}
		}
    	return 0;
	}
    sort(a.begin(), a.end());
    int x;
    for (int i = 0; i < n; i++)
    {
    	//cout << a[i];
        //cout << i + 1 << ' ' << a[i] * i- b << endl;
        if(a[i] * i - b > m)  {
        	x = i;
        	break;
		}
    	b += a[i];
    }
    cout << x;
//    auto it = upper_bound(c.begin(), c.end(), m);
//    int x = distance(c.begin(), it) -1;
//    cout << x;
}
