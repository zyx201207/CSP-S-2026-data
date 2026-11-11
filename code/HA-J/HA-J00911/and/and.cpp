#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin >> a >> b;
	int c[100086];
	for(int i = 1;i <= a;i++){
		cin >> c[i];
	}
	sort(c + 1,c + a + 1);
	cout << c[a];
	return 0;
}
