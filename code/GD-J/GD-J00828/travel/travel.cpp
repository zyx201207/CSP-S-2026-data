#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	string co, so, ct, st, ans;
	cin >> co >> so >> ct >> st;
	
	
	if(co == ct){
		ans += '1';
	}else{
		ans = "0000";
		cout << ans;
		return 0;
	}
	
	if(so.substr(0, 2) == st.substr(0, 2)){
		ans += '1';
	}else{
		ans += "000";
		cout << ans;
		return 0;
	}
	
	char cho = so[2], cht = st[2];
	if((cho >= 'A' && cho <= 'C' && cht >= 'A' && cht <= 'C') || (cho >= 'D' && cho <= 'F' && cht >= 'D' && cht <= 'F')){
		ans += '1';
	}else{
		ans += "00";
		cout << ans;
		return 0;
	}
	
	ll idxo = cho - 'A' + 1, idxt = cht - 'A' + 1;
	if(idxo == idxt + 1 || idxo == idxt - 1 || (idxo == 3 && idxt == 5) || (idxo == 5 && idxt == 3)){
		if(cho == 'C' && cht == 'D' || cho == 'D' && cht == 'C'){
			ans += '0';
		}else{
			ans += '1';
		}
	}else{
		ans += '0';
	}
	cout << ans;
	return 0;
}
