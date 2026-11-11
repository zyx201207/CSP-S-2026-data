#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
int n,m;
int a[N];
queue<int> q;
int to[N];
int ton[N];
int main ()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios:sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0;i<n;i++) cin >> a[i];
	int nn = n;
	while (nn--){
		memset(to,0,sizeof (to));
		int sum = 0;
		for (int i=abs(nn-n+1);i<n;i++){	
			if (to[a[i]]){
				to[a[i]] = 0;
				queue<int> q1;
				while(!q.empty()) {
					if (q.front() == a[i]){
						while(!q.empty())q.pop();
						break;
					}
					q1.push(q.front());
					q.pop();	
				}
				while (!q1.empty()){
					q.push(q1.front());
					q1.pop();
				}
				sum = q.size();
			}
			q.push(a[i]);
			sum++;
			to[a[i]]++;
		}
//		cout << "nn:" << nn << " " << "sum:" << sum << " ";
		for (int i=0;i<sum;i++){
			int ans = q.front();
			q.pop();
//			cout << ans << " ";
			ton[ans]++;
		}
	}
	for (int i=1;i<=m;i++) cout << ton[i] << " ";
	return 0;
}

