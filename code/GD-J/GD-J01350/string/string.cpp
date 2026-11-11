#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int a[N];
char c[N]; 
ll ans,len;
struct Rem{
	int num;
	char cc;
	int id; //1 is remnants on the left, 2 is right
};
Rem rem;
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	if(n == 1){
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		len += a[i];
	} 
	int i = 1, j = n;
	while(i < j){
		if(rem.num == 0){
			if(c[i] == c[j]){
				if(a[i] > a[j]){
					rem.num = a[i] - a[j];
					rem.cc = c[i];
					rem.id = 1;
					j--;
				}else if(a[i] < a[j]){
					rem.num = a[j] - a[i];
					rem.cc = c[j];
					rem.id = 2;
					i++;
				}
			}else{
				ans += min(a[i],a[j]);
				if(a[i] > a[j]){
					rem.num = a[i] - a[j];
					rem.cc = c[i];
					rem.id = 1;
					j--; 
				}else if(a[i] < a[j]){
					rem.num = a[j] - a[i];
					rem.cc = c[j];
					rem.id = 2;
					i++;
				}
			}
		}
		if(rem.id == 1){
			if(rem.cc == c[j]){
				if(rem.num > a[j]){
					rem.num = rem.num - a[j];
					rem.cc = rem.cc;
					rem.id = 1;
					j--;
				}else if(rem.num < a[j]){
					rem.num = a[j] - rem.num;
					rem.cc = c[j];
					rem.id = 2;
					i++;
				}
			}else{
				ans += min(rem.num,a[j]);
				if(rem.num > a[j]){
					rem.num = rem.num - a[j];
					rem.cc = rem.cc;
					rem.id = 1;
					j--;
				}else if(rem.num < a[j]){
					rem.num = a[j] - rem.num;
					rem.cc = a[j];
					rem.id = 2;
					i++;
				}
			}
		}else if(rem.id == 2){
			if(c[i] == rem.cc){
				if(a[i] > rem.num){
					rem.num = a[i] - rem.num;
					rem.cc = c[i];
					rem.id = 1;
					j--;
				}else if(a[i] < rem.num){
					rem.num = rem.num - a[i];
					rem.cc = rem.cc;
					rem.id = 2;
					i++;
				}
			}else{
				ans += min(a[i],rem.num);
				if(a[i] > rem.num){
					rem.num = a[i] - rem.num;
					rem.cc = c[i];
					rem.id = 1;
					j--;
				}else if(a[i] < rem.num){
					rem.num = rem.num - a[i];
					rem.cc = rem.cc;
					rem.id = 2;
					i++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
