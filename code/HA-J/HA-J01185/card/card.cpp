#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int D=1e6+10;
int n,m,A[D],dst[D],cnt=0;
stack<int> dstp;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>A[i];
	}
	while(n--) {
		int cnt=1;
		for(int i=cnt-1; i<n; i++) {
			if(dstp.empty()) {
				break;
			}
			int pnt=A[i];
			dstp.push(pnt);
			dst[i]=dstp.top();
			for(int j=0; j<dstp.size(); j++) {
				if(dst[j]==pnt) {
					for(int h=j; h>dstp.size(); h++) {
						dstp.pop();
					}
					dstp.push(pnt);
				} else {
					continue;
				}
			}
		}
		for(int i=0; i<n; i++) {
			if(dstp.top()!=n) {
				dstp.pop();
			} else {
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
