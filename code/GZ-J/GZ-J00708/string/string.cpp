//李泽瑞 GZ-J00708 
#include <bits/stdc++.h>
using namespace std;
int n;
long long len = 0;
vector<long long> pos;
map<long long, char> mp;
char GetL(long long P){
	//cout << "\n" << "已被调用，参数" << P << "\n";
	char L;
	for(int i = 1; i < n + 1; i++){
		if(P <= pos[i] && P > pos[i - 1]){
			L = mp[pos[i]];
		}
	}
	//cout << "返回" << L; 
	return L;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	pos.resize(n + 2);
	pos[0] = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		len += x;
		pos[i + 1] = len;
		cin >> mp[len];
	}
	int mid = 0;
	int ans = 0;
	if(len % 2 == 0){
		mid = len / 2;
		int l = mid, r = mid + 1;
		while(l >= 1 || r <= len){
			if(GetL(l) != GetL(r)){
				ans++;
			}
			l--;
			r++;
		}
	}else{
		mid = len / 2 + 1;
		int l = mid - 1, r = mid + 1;
		while(l >= 1 || r <= len){
			if(GetL(l) != GetL(r)){
				ans++;
				//cout << "检测到" <<  GetL(l) << l << "和" <<  GetL(r) << r << "不相等" << "\n";
			}
			l--;
			r++;
		}
	}
	cout << ans;
	//cout << len << " ";
	//cout << mid;
	return 0;
}
