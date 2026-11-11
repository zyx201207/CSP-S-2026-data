#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+10;
struct Period{
	int a;
	char c;
}data[N];
int n;

signed main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> data[i].a >> data[i].c;
	}
	int diff = 0, i = 1, j = n, result = 0;
	while(i <= j){
		diff = abs(data[i].a - data[j].a);
		if(data[i].c != data[j].c){
			result += min(data[i].a, data[j].a);
		}
		if(data[i].a < data[j].a){
			i++;
			data[j].a = diff;
		}
		else if(data[i].a > data[j].a){
			j--;
			data[i].a = diff;
		}
		else{
			data[i].a = 0;
			data[j].a = 0;
			i++;
			j--;
		}
	}
	cout << result;
	return 0;
}
