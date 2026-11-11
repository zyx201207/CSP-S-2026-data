#include <bits/stdc++.h>

using namespace std;

long long lrip, rrip;
long long n;
long long cnt = 0;
pair<long long, char> wq[200007];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for (int i = 0; i < n; i ++) {
		char c;
		long long sie;
		
		cin >> sie >> c;
		
		wq[i] = {sie, c};
	}
	rrip = n-1;
	lrip = 0;
	
	while (lrip < rrip) {
		if (wq[lrip].second == wq[rrip].second) {
			long long ct = wq[lrip].first - wq[rrip].first;
			if (ct > 0) {
				wq[lrip].first = ct;
				rrip--;
			} else if (ct < 0) {
				//cout << "rrip: " << rrip <<"\n";
				wq[rrip].first = (0-ct);
				lrip++;
			} else {
				lrip++;
				rrip--;
			}
		} else {
			long long mt = min(wq[lrip].first, wq[rrip].first);
			cnt += mt;
			
			if (mt == wq[lrip].first && mt == wq[rrip].first) {
				lrip++;
				rrip--;
				//cerr << "seecc  \n";
			}else if(mt == wq[lrip].first) {
				wq[rrip].first -= mt;
				lrip++;
			} else if (mt == wq[rrip].first) {
				wq[lrip].first -= mt;
				rrip--;
			}
			
			//cerr << "there is 2if run \n";
		}
	}
	
	cout << cnt;
	
	return 0;
}
