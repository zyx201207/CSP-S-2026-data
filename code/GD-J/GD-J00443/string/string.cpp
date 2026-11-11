#include <bits/stdc++.h>
using namespace std;
int n,L;
int ans;
string u = " ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;

	vector<int> num(n + 1,0);
	vector<string> cha(n + 1);
	
	for(int i = 1;i<=n;i++){
		cin >> num[i] >> cha[i];
		L += num[i];
	}
	if(n == 1){
		cout << 0;
		return 0;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j <= num[i];j++){
			u += cha[i];
		}
	}
	//cout << u << L;
	for(int i = 1;i<=L;i++){
		if(u[i] != u[L + 1 - i]){
			ans++;
		}
	}
	cout << ans / 2;
	return 0; 
}
