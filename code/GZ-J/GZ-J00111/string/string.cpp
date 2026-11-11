//GZ-J00111 凯里学院附属中学 尹宥嘉 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	string a;
	long long sizea = 0,c = 0;
	for(int i = 0;i < n;i ++){
		long long p;
		char t;
		cin >> p;
		cin >> t;
		for(int j = 0;j < p;j ++){
			a[sizea] = t;
			cout << a[sizea];
			sizea ++;
		}
	}
	for(int i = 0;i < sizea / 2;i ++){
		if(a[i] != a[sizea - i - 1]){
			c ++;
		}
	}
	cout << c;
	return 0;
}
