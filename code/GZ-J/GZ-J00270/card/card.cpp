//GZ-J00270,贵阳市第一实验中学，闵梦琪
#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	int n,m;
	cin >> n >>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=m;i++){
		cout << a[i] << " ";
	}
	return 0;
}
