#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N = 2e5 + 100; 

int t , ans;

struct node{
	int many;
	string w;
}num[N];

signed main(){
	freopen("string.in" , "r" , stdin); 
	freopen("string.out" , "w" , stdout);
	cin >> t;
	for (int i = 1 ; i <= t ; i++){
		cin >> num[i].many >> num[i].w;
	}
	int r = t , l = 1;
	while (true){
//		cout << num[l].many << " l: " << l << " " << num[r].many << " r: " << r << "   ans: "<< ans <<  "\n";
		if (r <= l) break;
		if (num[l].w != num[r].w){
			ans += min(num[l].many , num[r].many);
		}
		if (num[l].many < num[r].many){
			num[r].many -= num[l].many;
			l ++;
		}else if (num[l].many > num[r].many){
			num[l].many -= num[r].many;
			r --; 
		}else{
			r --;
			l ++; 
		}
	}
	cout << ans;
	return 0;
}
