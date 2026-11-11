#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int c, T;
    cin>>c>>T;
    while (T--) {
    	long long n, d;
    	cin>>n>>d;
    	vector<long long> points(n);
    	for (long long i=0;i<n;i++) {
    		cin>>points[i];
		}
		int ans=0;
		auto bfs=[&](int x, int y) -> bool{
			queue<long long> q;
			q.push(x);
			while (!q.empty()) {
				int g=0;
				int s=q.size();
				while (s--) {
					long long a=q.front();q.pop();
					long long wea=points[a];
					if (a==y) { g++; continue;}
					int b=a+1;
					while (b<n && abs(points[b]-points[a])<=d) {
						q.push(b++);
					} 
				}
				if (g!=0 && g!=2) return false;
				else if (g==2) return true;
			}
			return false;
	    };
	    for (int i=0;i<n-1;i++) {
	    	for (int j=i+1;j<n;j++) {
	    		ans+=bfs(i, j);
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}




