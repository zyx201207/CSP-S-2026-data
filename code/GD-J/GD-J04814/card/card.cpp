#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 7;
int n,m,a[N];
int mp[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
//	cout << n << "     " << m << endl;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		vector<int> vec;
		bool have[N] = {};
		for(int j = i;j <= n;j++){
			if(have[a[j]]){
				while(vec.back() != a[j]) have[vec.back()] = false,vec.pop_back();
			}
			else vec.push_back(a[j]);
			have[a[j]] = true;
		}
		for(int i = 0;i < (int)vec.size();i++) mp[vec[i]]++;
	}
	for(int i = 1;i <= m;i++) cout << mp[i] << ' ';
	return 0;
}
