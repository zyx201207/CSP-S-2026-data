#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N = 2e5 + 100; 

int n , m , num;

struct node{
	int num;
	string y;
	int many;
}ans[N];

string solve(string x , string y){
	string num;
	for (int i = 0 ; i < min(x.size() , y.size()) ; i++){
		if (x[i] == '1' && y[i] == '1')num += "1";
		else num += "0";
	}
	return num;
}

int fin(string x){
	int sum = 0 , two = 1;
	for (int i = 0 ; i < x.size() ; i++){
		if (x[i] == '1')sum += two;
		two *= 2;
	}
	return sum;
}

bool cmp(const node &a , const node &b){
	if (a.many == b.many) return a.num > b.num;
	return a.many > b.many;
}

signed main(){
	freopen("travel.in" , "r" , stdin); 
	freopen("travel.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++){
		cin >> ans[i].num;
		char tmp[N];
		int size = 1 , num0 = ans[i].num;
		ans[i].many = 1e18;
		while(true){
			if (num0 == 1){
				tmp[size] = '1';
				break;
			}
			if (num0 == 0){
				tmp[size] = '0';
				break;
			}
			if (num0 % 2 == 0) tmp[size] = '0';
			else{
				tmp[size] = '1';
				ans[i].many = min(ans[i].many , size);
			} 
			size ++;
			num0 /= 2;
		}
		ans[i].many = size - ans[i].many + 1;
		for (int j = 1 ; j <= size ; j++){
			ans[i].y += tmp[j];
		}
	}
	sort (ans + 1 , ans + n + 1 , cmp);
	string c = ans[1].y;
	for (int i = 2 ; i <= m ; i++){
		c = solve(c , ans[i].y);
	}
	cout << fin(c);
	return 0;	
}
