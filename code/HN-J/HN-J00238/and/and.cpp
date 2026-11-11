#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector< int > v[34];
bool cmp(int a , int b) {
	return a>=b;
}
int	ans , k;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n , m;
	cin>>n>>m;
	for(int i=1 ; i<=n ; i++) {
		int x , temp;
		cin>>x;
		temp = x;
		int cnt = 0;
		while(temp!=0) {
			if(temp&1 == 1) v[cnt].push_back(x);
			cnt++;
			temp = temp>>1;
			k = max(k , cnt);
		}
	}
	for(int i=k ; i>=0 ; i--) {
		int len = v[i].size();
//		cout<<i<<"\n";
//		if(len!=0) {
//			for(int j=0 ; j < len ; j++) cout<<v[i][j]<<" ";
//			cout<<"\n";
//		}
		if(len >= m) {
			sort(v[i].begin() , v[i].end() , cmp);
			ans = v[i][0];
			for(int j=0 ; j < m ; j++) {
				ans = ans & v[i][j];
			}
			break;
		}
	}

	cout<<ans;



	return 0;
}
























