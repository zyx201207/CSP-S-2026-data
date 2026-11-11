#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int n,d,x[302];
vector<int> E[302];
queue<pair<int,int> > pot;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin >> c >> t;
	
	while(t--){
		cin >> n >> d;
		for(int i = 1;i<n;i++){
			cin >> x[i];
			int t = i - 1;
			while(t > 0 and x[i]-x[t]<=d){
				E[i].push_back(t);
				E[t].push_back(i);
				t--;
			}
		}
		cout << 0 << endl;
	}
}
