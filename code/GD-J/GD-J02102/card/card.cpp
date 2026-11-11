#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N];
int t[N];
vector<int> v;
int find(int x){
	for(int i = 0;i < v.size();i++){
		if(x == v[i]) return i;
	}
	return -1;
}
signed main(){
	freopen("card.in","r",stdin);/////////////////////////////////////////////若要测试，请务必注释freopen
	freopen("card.out","w",stdout);///////////////////////////////////////////测试结束，请务必打开freopen
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		v.clear();
		for(int j = i;j <= n;j++){
			int f = find(a[j]);
			if(f == -1){
				v.push_back(a[j]);
			}
			else{
				for(int k = f;k < v.size();k++){
					v[k] = -1;
				}
				v.push_back(a[j]);
			}
		}
		for(int j = 0;j < v.size();j++){
			if(v[j] != -1) t[v[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << t[i] << " ";
	}
	return 0;
} 
