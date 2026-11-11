#include <bits/stdc++.h>
using namespace std;
struct node{
	int number;
	char word;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	vector <node> a(n+1);
	bool flag = true;
	int sum = 0;
	for (int i=1;i<=n;i++){
		cin >> a[i].number >> a[i].word;
		sum += a[i].number;
		if (a[i].number != 1) flag = false;
	}
	if (flag){
		int ans1 = 0;
		int l = 1,r = n;
		while (l != r){
			if (a[l].word != a[r].word) ans1++;
			l++;
			r--;
		}
		cout << ans1 << '\n';
	}
	else if (n == 1) cout << 0 << '\n';
	else{
		string s = "";
		int ans2 = 0;
		for (int i=1;i<=n;i++){
			int mu = a[i].number;
			char c = a[i].word;
			for (int j=1;j<=mu;j++) s+=c;
		}
		int l = 0,r = sum-1;
		while (l != r){
			if (s[l] != s[r]) ans2++;
			l++;
			r--;
		}
		cout << ans2 << '\n';
	}
	return 0;
}
