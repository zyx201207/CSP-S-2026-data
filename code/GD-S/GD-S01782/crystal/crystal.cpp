#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	long long n,m;
	cin >> n >> m;
	bool is1 = true,is2 = true;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		if(a[i] != i) is1 = false;
		if(i > 1 && a[i] - a[i - 1] != a[2] - a[1]) is2 = false;
	}
	if(is1 == true){//特殊性质A 
		cout << m + 1 << endl;
		return 0;
	}else if(is2 == true){//特殊性质B 
		cout << m / (a[2] - a[1]) + 1 << endl;
		return 0;
	}
	int Max = -1;
	for(int i = 1;i <= n;i++){
		for(int j = n;j > i;j--){
			int tmp = 0;
			for(int k = j - 1;k >= i;k--){
				tmp += a[j] - a[k];
			}
			if(tmp <= m){
				Max = max(Max,j - i + 1);
			}
		}
	}
	cout << Max << endl;
	return 0;
}
