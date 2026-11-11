#include<iostream>
#include<string>
using namespace std;
const int N = 2 * 1e5+5;
struct edge{
	int n;
	char str;
};
int main(){
	freopen("string5.in","r",stdin);
	int n;
	cin >> n;
	edge Str[N];
	int x;
	char y;
	long long all = 0;
	for(int i = 1; i <= n; i++){
		cin >> x >> y;
		Str[i].n = x;
		Str[i].str = y;
		all += x;
	}
	long long ans = 0;
	long long now_ptr_z = 0;
	long long used_z = 0;
//	for(int i = 1;i <= all;i++){
//		if(used_z < i){
//			used_z += Str[now_ptr_z+1].n;
//			now_ptr_z++;
//		}
//		cout << now_ptr_z << " " << i - (used_z - Str[now_ptr_z].n) << endl;
//	}
	long long now_ptr_d = n;
	long long used_d = 0;
	long long cc;
	long long now_a;
//	for(int i = 1;i <= all;i++){
//		if(used_d < i){
//			used_d += Str[now_ptr_d].n;
//			cc = used_d;
//			now_a = Str[now_ptr_d].n;
//			now_ptr_d--;
//		}
////		cout << "i: " << i << " ²îÖµ: " << now_a << "»º´æ: " << cc << endl;
//		cout << now_ptr_d + 1 << " " << now_a - (i - cc + now_a) + 1 << endl;
//	}
	for(int i = 1;i <= all / 2;i++){
		if(used_z < i){
			used_z += Str[now_ptr_z+1].n;
			now_ptr_z++;
		}
		if(used_d < i){
			used_d += Str[now_ptr_d].n;
			cc = used_d;
			now_a = Str[now_ptr_d].n;
			now_ptr_d--;
		}
		if(Str[now_ptr_z].str != Str[now_ptr_d + 1].str){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
