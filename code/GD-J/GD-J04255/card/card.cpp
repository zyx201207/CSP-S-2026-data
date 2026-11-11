#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	vector<ll> a(n);
	vector<ll> desk;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < m;i++){
		for(int j = i;j < n;j++) 
		{
			if(find(desk.begin(),desk.end(),a[j]) == desk.end()) desk.push_back(a[j]);
			else{
				for(auto it = a.begin();it != find(desk.begin(),desk.end(),a[j]);it++) desk.erase(it);
			}
		}
		cout << desk.size() << ' ';
	}
	return 0;
}
