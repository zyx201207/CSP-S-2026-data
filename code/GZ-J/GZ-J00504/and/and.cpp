//中央民族大学附属中学贵阳学校 夏宇森 GZ-J00504
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6;
int n, m, jz[35];
ll a[N], ans;
vector<int> jzs[35], tmp;
void get2(ll x, ll xi){
	int tot = 1;
	memset(jz, 0, sizeof jz);
	memset(jzs, 0, sizeof jzs);
	while(x){
		if(x&1){
			jz[tot]+=1;
			jzs[tot].push_back(xi);
		}
		x>>=1; tot++;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		get2(a[i], i);
	}
	for(int i = 34; i >0; --i){
		if(jz[i] == m){
			ans = a[jzs[i][0]];
			for(int j = 1; j < jzs[i].size(); j++){
				ans &= a[jzs[i][j]];
			}
			cout << ans;
			return 0;
		}
		else if(jz[i] > m){
			for(int j = 0; j < jzs[i].size(); j++){
				tmp.push_back(jzs[i][j]);
			}
			for(int j = 0 ;j < jzs[i].size(); j++){
				get2(a[tmp[j]], tmp[j]);
			}
		}
	}
	ans = a[tmp[0]];
	for(int i = 1; i < tmp.size(); i++){
		ans&= a[tmp[i]];
	}
	cout << ans;
	return 0;
} 
