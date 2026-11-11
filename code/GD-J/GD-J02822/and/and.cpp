#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a;
	vector<int> num = {};
	cin >> n >> m;
	for (int i = 0;i < n;i++){
		cin >> a;
		num.push_back(a);
	}
	cout << num[n-1];
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
