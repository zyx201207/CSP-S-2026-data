#include<bits/stdc++.h>
using namespace std;
struct Char{
	long long num;
	char ch;
};
int n;
long long ans;
vector<Char> a(1);
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		long long num;
		char ch;
		
		cin >> num >> ch;
		if(i != 1 and a[a.size()-1].ch == ch){
			a[a.size()-1].num += num;
		}else{
			a.push_back({num,ch});
		}
	}
	
	for(int l = 1,r = a.size()-1;l <= r;){
		if(a[l].ch != a[r].ch){
			ans += min(a[l].num,a[r].num);
			if(a[l].num > a[r].num){
				a[l].num -= a[r].num;
				a[r].num = 0;
				r--;
			}else if(a[l].num < a[r].num){
				a[r].num -= a[l].num;
				a[l].num = 0;
				l++;
			}else{
				l++; r--;
			}
		}else{
			if(a[l].num > a[r].num){
				a[l].num -= a[r].num;
				a[r].num = 0;
				r--;
			}else if(a[l].num < a[r].num){
				a[r].num -= a[l].num;
				a[l].num = 0;
				l++;
			}else{
				l++; r--;
			}
		}
	}
	
	cout << ans << '\n';
	return 0;
}
